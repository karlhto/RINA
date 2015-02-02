//
// Copyright © 2014 PRISTINE Consortium (http://ict-pristine.eu)
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "IDPerNFlow.h"

Define_Module(IDPerNFlow);

std::string IDPerNFlow::generateID(PDU* pdu)
{
    std::ostringstream id;
    id << pdu->getSrcAddr().getIpcAddress().getName() << "_"
       << pdu->getConnId().getSrcCepId();

    return id.str();
}

std::string IDPerNFlow::generateID(Flow* flow)
{
    std::ostringstream id;
    id << flow->getSrcAddr().getIpcAddress().getName() << "_"
       << flow->getConId().getSrcCepId();

    return id.str();
}