// The MIT License (MIT)
//
// Copyright (c) 2014-2016 Brno University of Technology, PRISTINE project
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#ifndef MiniTable_H_
#define MiniTable_H_

#include "DIF/RMT/PDUForwarding/IntMiniForwarding.h"

#include <map>
#include <string>
#include <vector>

namespace MiniTable {

using namespace std;

typedef map<string, RMTPort*> FWDTable;
typedef FWDTable::iterator FWDTableIt;

class MiniTable: public IntMiniForwarding {

public:
    // Lookup function, return a list of RMTPorts to forward a PDU/Address+qos.
    vector<RMTPort * > lookup(const PDU * pdu);
    vector<RMTPort * > lookup(const Address &dst, const std::string& qos);

    // Returns a representation of the Forwarding Knowledge
    string toString();

    //Insert/Remove an entry
    void insert(const std::string &addr, RMTPort * port);
    void insert(const Address &addr, RMTPort * port);
    void remove(const std::string &addr);
    void remove(const Address &addr);
    void clean();

    void finish();

protected:
    FWDTable table;

    // Called after initialize
    void onPolicyInit();
};

}

#endif /* MiniTable_H_ */
