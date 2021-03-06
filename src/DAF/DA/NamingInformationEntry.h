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

#ifndef NAMINGINFORMATIONENTRY_H_
#define NAMINGINFORMATIONENTRY_H_

//RINASim libraries
#include "Common/APN.h"

class NamingInformationEntry {
  public:
    NamingInformationEntry(const APN& napn);
    virtual ~NamingInformationEntry();

    bool operator== (const NamingInformationEntry& other) const;

    const APN& getApn() const;
    void setApn(const APN& apn);
    const std::list<APN>& getSynonyms() const;
    void setSynonyms(const std::list<APN>& synonyms);

    std::string info() const;

    void addSynonym(const APN& synonym);
    bool hasSynonym(const APN& synonym);
  private:
    APN Apn;
    APNList Synonyms;
};


//Free function
std::ostream& operator<< (std::ostream& os, const NamingInformationEntry& nie);

#endif /* NAMINGINFORMATIONENTRY_H_ */
