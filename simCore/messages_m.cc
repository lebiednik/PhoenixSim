//
// Generated file, do not edit! Created by opp_msgc 4.5 from simCore/messages.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "messages_m.h"

USING_NAMESPACE


// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




// Template rule for outputting std::vector<T> types
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("PSE_STATE");
    if (!e) enums.getInstance()->add(e = new cEnum("PSE_STATE"));
    e->insert(PSE_OFF, "PSE_OFF");
    e->insert(PSE_ON, "PSE_ON");
);

EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("ElectronicMessageTypes");
    if (!e) enums.getInstance()->add(e = new cEnum("ElectronicMessageTypes"));
    e->insert(dataPacket, "dataPacket");
    e->insert(pathSetup, "pathSetup");
    e->insert(pathTeardown, "pathTeardown");
    e->insert(pathBlocked, "pathBlocked");
    e->insert(pathACK, "pathACK");
    e->insert(pathRespond, "pathRespond");
    e->insert(pathUnknown, "pathUnknown");
    e->insert(pathBlockedTurnaround, "pathBlockedTurnaround");
    e->insert(pathSetupCancelled, "pathSetupCancelled");
    e->insert(router_bufferAck, "router_bufferAck");
    e->insert(grantDataTx, "grantDataTx");
    e->insert(requestDataTx, "requestDataTx");
    e->insert(router_unblock, "router_unblock");
    e->insert(router_xbar, "router_xbar");
    e->insert(router_arb_req, "router_arb_req");
    e->insert(router_arb_grant, "router_arb_grant");
    e->insert(router_arb_deny, "router_arb_deny");
    e->insert(router_arb_unblock, "router_arb_unblock");
    e->insert(router_pse_setup, "router_pse_setup");
    e->insert(router_change_blocked, "router_change_blocked");
    e->insert(router_change_cancel, "router_change_cancel");
    e->insert(router_arb_escape, "router_arb_escape");
    e->insert(router_power_arbiter, "router_power_arbiter");
    e->insert(router_power_crossbar, "router_power_crossbar");
    e->insert(router_power_inport, "router_power_inport");
    e->insert(router_grant_destroy, "router_grant_destroy");
    e->insert(proc_req_send, "proc_req_send");
    e->insert(proc_grant, "proc_grant");
    e->insert(proc_data, "proc_data");
    e->insert(proc_msg_sent, "proc_msg_sent");
    e->insert(router_partial_blocked, "router_partial_blocked");
    e->insert(collision_detected_TX, "collision_detected_TX");
    e->insert(collision_detected_RX, "collision_detected_RX");
    e->insert(medium_free, "medium_free");
    e->insert(medium_occupied, "medium_occupied");
    e->insert(transmission_OK, "transmission_OK");
    e->insert(token, "token");
    e->insert(wireless_ACK, "wireless_ACK");
    e->insert(wireless_NACK, "wireless_NACK");
    e->insert(broadcast_NACK, "broadcast_NACK");
    e->insert(startNACKperiod, "startNACKperiod");
    e->insert(stopNACKperiod, "stopNACKperiod");
);

EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("ProcessorCntrlTypes");
    if (!e) enums.getInstance()->add(e = new cEnum("ProcessorCntrlTypes"));
);

EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("PhotonicMessageTypes");
    if (!e) enums.getInstance()->add(e = new cEnum("PhotonicMessageTypes"));
    e->insert(TXstart, "TXstart");
    e->insert(TXstop, "TXstop");
    e->insert(Llevel, "Llevel");
    e->insert(Nstart, "Nstart");
    e->insert(Nstop, "Nstop");
    e->insert(VTXstart, "VTXstart");
    e->insert(VTXstop, "VTXstop");
    e->insert(TXpulse, "TXpulse");
);

EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("ProcMsgType");
    if (!e) enums.getInstance()->add(e = new cEnum("ProcMsgType"));
    e->insert(SM_read, "SM_read");
    e->insert(SM_write, "SM_write");
    e->insert(DM_readLocal, "DM_readLocal");
    e->insert(DM_readRemote, "DM_readRemote");
    e->insert(DM_writeLocal, "DM_writeLocal");
    e->insert(DM_writeRemote, "DM_writeRemote");
    e->insert(M_readResponse, "M_readResponse");
    e->insert(MPI_send, "MPI_send");
    e->insert(CPU_op, "CPU_op");
    e->insert(snoopReq, "snoopReq");
    e->insert(snoopResp, "snoopResp");
    e->insert(hybridBlockW, "hybridBlockW");
    e->insert(hybridUnblockW, "hybridUnblockW");
    e->insert(procSynch, "procSynch");
);

EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("DRAM_CntrlTypes");
    if (!e) enums.getInstance()->add(e = new cEnum("DRAM_CntrlTypes"));
    e->insert(Row_Access, "Row_Access");
    e->insert(Col_Access, "Col_Access");
    e->insert(Precharge, "Precharge");
    e->insert(Write_Data, "Write_Data");
);

EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("MemoryAccessType");
    if (!e) enums.getInstance()->add(e = new cEnum("MemoryAccessType"));
    e->insert(MemoryIFetechCmd, "MemoryIFetechCmd");
    e->insert(MemoryWriteCmd, "MemoryWriteCmd");
    e->insert(MemoryReadCmd, "MemoryReadCmd");
    e->insert(MemoryPrefetchCmd, "MemoryPrefetchCmd");
);

Register_Class(ElectronicMessage);

ElectronicMessage::ElectronicMessage(const char *name, int kind) : ::cPacket(name,kind)
{
    this->Id_var = 0;
    this->SrcId_var = 0;
    this->DstId_var = 0;
    this->virtualChannel_var = 0;
    this->MsgType_var = 0;
    this->data_var = 0;
    this->time_var = 0;
    this->bcast_var = false;
    this->RTB_var = 0;
    this->LTB_var = 0;
    this->sourceBit_var = 1;
    this->numRetries_var = 0;
    this->BOcounter_var = 0;
    circuitAvailable_arraysize = 0;
    this->circuitAvailable_var = 0;
    circuitCheck_arraysize = 0;
    this->circuitCheck_var = 0;
}

ElectronicMessage::ElectronicMessage(const ElectronicMessage& other) : ::cPacket(other)
{
    circuitAvailable_arraysize = 0;
    this->circuitAvailable_var = 0;
    circuitCheck_arraysize = 0;
    this->circuitCheck_var = 0;
    copy(other);
}

ElectronicMessage::~ElectronicMessage()
{
    delete [] circuitAvailable_var;
    delete [] circuitCheck_var;
}

ElectronicMessage& ElectronicMessage::operator=(const ElectronicMessage& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void ElectronicMessage::copy(const ElectronicMessage& other)
{
    this->Id_var = other.Id_var;
    this->SrcId_var = other.SrcId_var;
    this->DstId_var = other.DstId_var;
    this->virtualChannel_var = other.virtualChannel_var;
    this->MsgType_var = other.MsgType_var;
    this->data_var = other.data_var;
    this->time_var = other.time_var;
    this->bcast_var = other.bcast_var;
    this->RTB_var = other.RTB_var;
    this->LTB_var = other.LTB_var;
    this->sourceBit_var = other.sourceBit_var;
    this->numRetries_var = other.numRetries_var;
    this->BOcounter_var = other.BOcounter_var;
    delete [] this->circuitAvailable_var;
    this->circuitAvailable_var = (other.circuitAvailable_arraysize==0) ? NULL : new bool[other.circuitAvailable_arraysize];
    circuitAvailable_arraysize = other.circuitAvailable_arraysize;
    for (unsigned int i=0; i<circuitAvailable_arraysize; i++)
        this->circuitAvailable_var[i] = other.circuitAvailable_var[i];
    delete [] this->circuitCheck_var;
    this->circuitCheck_var = (other.circuitCheck_arraysize==0) ? NULL : new bool[other.circuitCheck_arraysize];
    circuitCheck_arraysize = other.circuitCheck_arraysize;
    for (unsigned int i=0; i<circuitCheck_arraysize; i++)
        this->circuitCheck_var[i] = other.circuitCheck_var[i];
}

void ElectronicMessage::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->Id_var);
    doPacking(b,this->SrcId_var);
    doPacking(b,this->DstId_var);
    doPacking(b,this->virtualChannel_var);
    doPacking(b,this->MsgType_var);
    doPacking(b,this->data_var);
    doPacking(b,this->time_var);
    doPacking(b,this->bcast_var);
    doPacking(b,this->RTB_var);
    doPacking(b,this->LTB_var);
    doPacking(b,this->sourceBit_var);
    doPacking(b,this->numRetries_var);
    doPacking(b,this->BOcounter_var);
    b->pack(circuitAvailable_arraysize);
    doPacking(b,this->circuitAvailable_var,circuitAvailable_arraysize);
    b->pack(circuitCheck_arraysize);
    doPacking(b,this->circuitCheck_var,circuitCheck_arraysize);
}

void ElectronicMessage::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->Id_var);
    doUnpacking(b,this->SrcId_var);
    doUnpacking(b,this->DstId_var);
    doUnpacking(b,this->virtualChannel_var);
    doUnpacking(b,this->MsgType_var);
    doUnpacking(b,this->data_var);
    doUnpacking(b,this->time_var);
    doUnpacking(b,this->bcast_var);
    doUnpacking(b,this->RTB_var);
    doUnpacking(b,this->LTB_var);
    doUnpacking(b,this->sourceBit_var);
    doUnpacking(b,this->numRetries_var);
    doUnpacking(b,this->BOcounter_var);
    delete [] this->circuitAvailable_var;
    b->unpack(circuitAvailable_arraysize);
    if (circuitAvailable_arraysize==0) {
        this->circuitAvailable_var = 0;
    } else {
        this->circuitAvailable_var = new bool[circuitAvailable_arraysize];
        doUnpacking(b,this->circuitAvailable_var,circuitAvailable_arraysize);
    }
    delete [] this->circuitCheck_var;
    b->unpack(circuitCheck_arraysize);
    if (circuitCheck_arraysize==0) {
        this->circuitCheck_var = 0;
    } else {
        this->circuitCheck_var = new bool[circuitCheck_arraysize];
        doUnpacking(b,this->circuitCheck_var,circuitCheck_arraysize);
    }
}

int ElectronicMessage::getId() const
{
    return Id_var;
}

void ElectronicMessage::setId(int Id)
{
    this->Id_var = Id;
}

long ElectronicMessage::getSrcId() const
{
    return SrcId_var;
}

void ElectronicMessage::setSrcId(long SrcId)
{
    this->SrcId_var = SrcId;
}

long ElectronicMessage::getDstId() const
{
    return DstId_var;
}

void ElectronicMessage::setDstId(long DstId)
{
    this->DstId_var = DstId;
}

int ElectronicMessage::getVirtualChannel() const
{
    return virtualChannel_var;
}

void ElectronicMessage::setVirtualChannel(int virtualChannel)
{
    this->virtualChannel_var = virtualChannel;
}

int ElectronicMessage::getMsgType() const
{
    return MsgType_var;
}

void ElectronicMessage::setMsgType(int MsgType)
{
    this->MsgType_var = MsgType;
}

long ElectronicMessage::getData() const
{
    return data_var;
}

void ElectronicMessage::setData(long data)
{
    this->data_var = data;
}

simtime_t ElectronicMessage::getTime() const
{
    return time_var;
}

void ElectronicMessage::setTime(simtime_t time)
{
    this->time_var = time;
}

bool ElectronicMessage::getBcast() const
{
    return bcast_var;
}

void ElectronicMessage::setBcast(bool bcast)
{
    this->bcast_var = bcast;
}

int ElectronicMessage::getRTB() const
{
    return RTB_var;
}

void ElectronicMessage::setRTB(int RTB)
{
    this->RTB_var = RTB;
}

int ElectronicMessage::getLTB() const
{
    return LTB_var;
}

void ElectronicMessage::setLTB(int LTB)
{
    this->LTB_var = LTB;
}

int ElectronicMessage::getSourceBit() const
{
    return sourceBit_var;
}

void ElectronicMessage::setSourceBit(int sourceBit)
{
    this->sourceBit_var = sourceBit;
}

int ElectronicMessage::getNumRetries() const
{
    return numRetries_var;
}

void ElectronicMessage::setNumRetries(int numRetries)
{
    this->numRetries_var = numRetries;
}

int ElectronicMessage::getBOcounter() const
{
    return BOcounter_var;
}

void ElectronicMessage::setBOcounter(int BOcounter)
{
    this->BOcounter_var = BOcounter;
}

void ElectronicMessage::setCircuitAvailableArraySize(unsigned int size)
{
    bool *circuitAvailable_var2 = (size==0) ? NULL : new bool[size];
    unsigned int sz = circuitAvailable_arraysize < size ? circuitAvailable_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        circuitAvailable_var2[i] = this->circuitAvailable_var[i];
    for (unsigned int i=sz; i<size; i++)
        circuitAvailable_var2[i] = 0;
    circuitAvailable_arraysize = size;
    delete [] this->circuitAvailable_var;
    this->circuitAvailable_var = circuitAvailable_var2;
}

unsigned int ElectronicMessage::getCircuitAvailableArraySize() const
{
    return circuitAvailable_arraysize;
}

bool ElectronicMessage::getCircuitAvailable(unsigned int k) const
{
    if (k>=circuitAvailable_arraysize) throw cRuntimeError("Array of size %d indexed by %d", circuitAvailable_arraysize, k);
    return circuitAvailable_var[k];
}

void ElectronicMessage::setCircuitAvailable(unsigned int k, bool circuitAvailable)
{
    if (k>=circuitAvailable_arraysize) throw cRuntimeError("Array of size %d indexed by %d", circuitAvailable_arraysize, k);
    this->circuitAvailable_var[k] = circuitAvailable;
}

void ElectronicMessage::setCircuitCheckArraySize(unsigned int size)
{
    bool *circuitCheck_var2 = (size==0) ? NULL : new bool[size];
    unsigned int sz = circuitCheck_arraysize < size ? circuitCheck_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        circuitCheck_var2[i] = this->circuitCheck_var[i];
    for (unsigned int i=sz; i<size; i++)
        circuitCheck_var2[i] = 0;
    circuitCheck_arraysize = size;
    delete [] this->circuitCheck_var;
    this->circuitCheck_var = circuitCheck_var2;
}

unsigned int ElectronicMessage::getCircuitCheckArraySize() const
{
    return circuitCheck_arraysize;
}

bool ElectronicMessage::getCircuitCheck(unsigned int k) const
{
    if (k>=circuitCheck_arraysize) throw cRuntimeError("Array of size %d indexed by %d", circuitCheck_arraysize, k);
    return circuitCheck_var[k];
}

void ElectronicMessage::setCircuitCheck(unsigned int k, bool circuitCheck)
{
    if (k>=circuitCheck_arraysize) throw cRuntimeError("Array of size %d indexed by %d", circuitCheck_arraysize, k);
    this->circuitCheck_var[k] = circuitCheck;
}

class ElectronicMessageDescriptor : public cClassDescriptor
{
  public:
    ElectronicMessageDescriptor();
    virtual ~ElectronicMessageDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(ElectronicMessageDescriptor);

ElectronicMessageDescriptor::ElectronicMessageDescriptor() : cClassDescriptor("ElectronicMessage", "cPacket")
{
}

ElectronicMessageDescriptor::~ElectronicMessageDescriptor()
{
}

bool ElectronicMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<ElectronicMessage *>(obj)!=NULL;
}

const char *ElectronicMessageDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int ElectronicMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 15+basedesc->getFieldCount(object) : 15;
}

unsigned int ElectronicMessageDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<15) ? fieldTypeFlags[field] : 0;
}

const char *ElectronicMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "Id",
        "SrcId",
        "DstId",
        "virtualChannel",
        "MsgType",
        "data",
        "time",
        "bcast",
        "RTB",
        "LTB",
        "sourceBit",
        "numRetries",
        "BOcounter",
        "circuitAvailable",
        "circuitCheck",
    };
    return (field>=0 && field<15) ? fieldNames[field] : NULL;
}

int ElectronicMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='I' && strcmp(fieldName, "Id")==0) return base+0;
    if (fieldName[0]=='S' && strcmp(fieldName, "SrcId")==0) return base+1;
    if (fieldName[0]=='D' && strcmp(fieldName, "DstId")==0) return base+2;
    if (fieldName[0]=='v' && strcmp(fieldName, "virtualChannel")==0) return base+3;
    if (fieldName[0]=='M' && strcmp(fieldName, "MsgType")==0) return base+4;
    if (fieldName[0]=='d' && strcmp(fieldName, "data")==0) return base+5;
    if (fieldName[0]=='t' && strcmp(fieldName, "time")==0) return base+6;
    if (fieldName[0]=='b' && strcmp(fieldName, "bcast")==0) return base+7;
    if (fieldName[0]=='R' && strcmp(fieldName, "RTB")==0) return base+8;
    if (fieldName[0]=='L' && strcmp(fieldName, "LTB")==0) return base+9;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceBit")==0) return base+10;
    if (fieldName[0]=='n' && strcmp(fieldName, "numRetries")==0) return base+11;
    if (fieldName[0]=='B' && strcmp(fieldName, "BOcounter")==0) return base+12;
    if (fieldName[0]=='c' && strcmp(fieldName, "circuitAvailable")==0) return base+13;
    if (fieldName[0]=='c' && strcmp(fieldName, "circuitCheck")==0) return base+14;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *ElectronicMessageDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "long",
        "long",
        "int",
        "int",
        "long",
        "simtime_t",
        "bool",
        "int",
        "int",
        "int",
        "int",
        "int",
        "bool",
        "bool",
    };
    return (field>=0 && field<15) ? fieldTypeStrings[field] : NULL;
}

const char *ElectronicMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 4:
            if (!strcmp(propertyname,"enum")) return "ElectronicMessageTypes";
            return NULL;
        default: return NULL;
    }
}

int ElectronicMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    ElectronicMessage *pp = (ElectronicMessage *)object; (void)pp;
    switch (field) {
        case 13: return pp->getCircuitAvailableArraySize();
        case 14: return pp->getCircuitCheckArraySize();
        default: return 0;
    }
}

std::string ElectronicMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    ElectronicMessage *pp = (ElectronicMessage *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getId());
        case 1: return long2string(pp->getSrcId());
        case 2: return long2string(pp->getDstId());
        case 3: return long2string(pp->getVirtualChannel());
        case 4: return long2string(pp->getMsgType());
        case 5: return long2string(pp->getData());
        case 6: return double2string(pp->getTime());
        case 7: return bool2string(pp->getBcast());
        case 8: return long2string(pp->getRTB());
        case 9: return long2string(pp->getLTB());
        case 10: return long2string(pp->getSourceBit());
        case 11: return long2string(pp->getNumRetries());
        case 12: return long2string(pp->getBOcounter());
        case 13: return bool2string(pp->getCircuitAvailable(i));
        case 14: return bool2string(pp->getCircuitCheck(i));
        default: return "";
    }
}

bool ElectronicMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    ElectronicMessage *pp = (ElectronicMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setId(string2long(value)); return true;
        case 1: pp->setSrcId(string2long(value)); return true;
        case 2: pp->setDstId(string2long(value)); return true;
        case 3: pp->setVirtualChannel(string2long(value)); return true;
        case 4: pp->setMsgType(string2long(value)); return true;
        case 5: pp->setData(string2long(value)); return true;
        case 6: pp->setTime(string2double(value)); return true;
        case 7: pp->setBcast(string2bool(value)); return true;
        case 8: pp->setRTB(string2long(value)); return true;
        case 9: pp->setLTB(string2long(value)); return true;
        case 10: pp->setSourceBit(string2long(value)); return true;
        case 11: pp->setNumRetries(string2long(value)); return true;
        case 12: pp->setBOcounter(string2long(value)); return true;
        case 13: pp->setCircuitAvailable(i,string2bool(value)); return true;
        case 14: pp->setCircuitCheck(i,string2bool(value)); return true;
        default: return false;
    }
}

const char *ElectronicMessageDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *ElectronicMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    ElectronicMessage *pp = (ElectronicMessage *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(PathSetupMsg);

PathSetupMsg::PathSetupMsg(const char *name, int kind) : ::ElectronicMessage(name,kind)
{
    this->allowedTx_var = 0;
    this->dataWidth_var = 0;
    this->blockedAddr_var = 0;
}

PathSetupMsg::PathSetupMsg(const PathSetupMsg& other) : ::ElectronicMessage(other)
{
    copy(other);
}

PathSetupMsg::~PathSetupMsg()
{
}

PathSetupMsg& PathSetupMsg::operator=(const PathSetupMsg& other)
{
    if (this==&other) return *this;
    ::ElectronicMessage::operator=(other);
    copy(other);
    return *this;
}

void PathSetupMsg::copy(const PathSetupMsg& other)
{
    this->allowedTx_var = other.allowedTx_var;
    this->dataWidth_var = other.dataWidth_var;
    this->blockedAddr_var = other.blockedAddr_var;
}

void PathSetupMsg::parsimPack(cCommBuffer *b)
{
    ::ElectronicMessage::parsimPack(b);
    doPacking(b,this->allowedTx_var);
    doPacking(b,this->dataWidth_var);
    doPacking(b,this->blockedAddr_var);
}

void PathSetupMsg::parsimUnpack(cCommBuffer *b)
{
    ::ElectronicMessage::parsimUnpack(b);
    doUnpacking(b,this->allowedTx_var);
    doUnpacking(b,this->dataWidth_var);
    doUnpacking(b,this->blockedAddr_var);
}

int PathSetupMsg::getAllowedTx() const
{
    return allowedTx_var;
}

void PathSetupMsg::setAllowedTx(int allowedTx)
{
    this->allowedTx_var = allowedTx;
}

int PathSetupMsg::getDataWidth() const
{
    return dataWidth_var;
}

void PathSetupMsg::setDataWidth(int dataWidth)
{
    this->dataWidth_var = dataWidth;
}

long PathSetupMsg::getBlockedAddr() const
{
    return blockedAddr_var;
}

void PathSetupMsg::setBlockedAddr(long blockedAddr)
{
    this->blockedAddr_var = blockedAddr;
}

class PathSetupMsgDescriptor : public cClassDescriptor
{
  public:
    PathSetupMsgDescriptor();
    virtual ~PathSetupMsgDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(PathSetupMsgDescriptor);

PathSetupMsgDescriptor::PathSetupMsgDescriptor() : cClassDescriptor("PathSetupMsg", "ElectronicMessage")
{
}

PathSetupMsgDescriptor::~PathSetupMsgDescriptor()
{
}

bool PathSetupMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<PathSetupMsg *>(obj)!=NULL;
}

const char *PathSetupMsgDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int PathSetupMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int PathSetupMsgDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *PathSetupMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "allowedTx",
        "dataWidth",
        "blockedAddr",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int PathSetupMsgDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='a' && strcmp(fieldName, "allowedTx")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "dataWidth")==0) return base+1;
    if (fieldName[0]=='b' && strcmp(fieldName, "blockedAddr")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *PathSetupMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "long",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *PathSetupMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int PathSetupMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    PathSetupMsg *pp = (PathSetupMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string PathSetupMsgDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    PathSetupMsg *pp = (PathSetupMsg *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getAllowedTx());
        case 1: return long2string(pp->getDataWidth());
        case 2: return long2string(pp->getBlockedAddr());
        default: return "";
    }
}

bool PathSetupMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    PathSetupMsg *pp = (PathSetupMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setAllowedTx(string2long(value)); return true;
        case 1: pp->setDataWidth(string2long(value)); return true;
        case 2: pp->setBlockedAddr(string2long(value)); return true;
        default: return false;
    }
}

const char *PathSetupMsgDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *PathSetupMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    PathSetupMsg *pp = (PathSetupMsg *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(PhotonicMessage);

PhotonicMessage::PhotonicMessage(const char *name, int kind) : ::cPacket(name,kind)
{
    this->MsgType_var = 0;
    this->Id_var = 0;
    this->PacketStat_var = 0;
}

PhotonicMessage::PhotonicMessage(const PhotonicMessage& other) : ::cPacket(other)
{
    copy(other);
}

PhotonicMessage::~PhotonicMessage()
{
}

PhotonicMessage& PhotonicMessage::operator=(const PhotonicMessage& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void PhotonicMessage::copy(const PhotonicMessage& other)
{
    this->MsgType_var = other.MsgType_var;
    this->Id_var = other.Id_var;
    this->PacketStat_var = other.PacketStat_var;
}

void PhotonicMessage::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->MsgType_var);
    doPacking(b,this->Id_var);
    doPacking(b,this->PacketStat_var);
}

void PhotonicMessage::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->MsgType_var);
    doUnpacking(b,this->Id_var);
    doUnpacking(b,this->PacketStat_var);
}

int PhotonicMessage::getMsgType() const
{
    return MsgType_var;
}

void PhotonicMessage::setMsgType(int MsgType)
{
    this->MsgType_var = MsgType;
}

int PhotonicMessage::getId() const
{
    return Id_var;
}

void PhotonicMessage::setId(int Id)
{
    this->Id_var = Id;
}

long PhotonicMessage::getPacketStat() const
{
    return PacketStat_var;
}

void PhotonicMessage::setPacketStat(long PacketStat)
{
    this->PacketStat_var = PacketStat;
}

class PhotonicMessageDescriptor : public cClassDescriptor
{
  public:
    PhotonicMessageDescriptor();
    virtual ~PhotonicMessageDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(PhotonicMessageDescriptor);

PhotonicMessageDescriptor::PhotonicMessageDescriptor() : cClassDescriptor("PhotonicMessage", "cPacket")
{
}

PhotonicMessageDescriptor::~PhotonicMessageDescriptor()
{
}

bool PhotonicMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<PhotonicMessage *>(obj)!=NULL;
}

const char *PhotonicMessageDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int PhotonicMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int PhotonicMessageDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *PhotonicMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "MsgType",
        "Id",
        "PacketStat",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int PhotonicMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='M' && strcmp(fieldName, "MsgType")==0) return base+0;
    if (fieldName[0]=='I' && strcmp(fieldName, "Id")==0) return base+1;
    if (fieldName[0]=='P' && strcmp(fieldName, "PacketStat")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *PhotonicMessageDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "long",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *PhotonicMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "PhotonicMessageTypes";
            return NULL;
        default: return NULL;
    }
}

int PhotonicMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    PhotonicMessage *pp = (PhotonicMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string PhotonicMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    PhotonicMessage *pp = (PhotonicMessage *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getMsgType());
        case 1: return long2string(pp->getId());
        case 2: return long2string(pp->getPacketStat());
        default: return "";
    }
}

bool PhotonicMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    PhotonicMessage *pp = (PhotonicMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setMsgType(string2long(value)); return true;
        case 1: pp->setId(string2long(value)); return true;
        case 2: pp->setPacketStat(string2long(value)); return true;
        default: return false;
    }
}

const char *PhotonicMessageDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *PhotonicMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    PhotonicMessage *pp = (PhotonicMessage *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(VWTcntrlMsg);

VWTcntrlMsg::VWTcntrlMsg(const char *name, int kind) : ::ElectronicMessage(name,kind)
{
    this->wavelengths_var = 0;
}

VWTcntrlMsg::VWTcntrlMsg(const VWTcntrlMsg& other) : ::ElectronicMessage(other)
{
    copy(other);
}

VWTcntrlMsg::~VWTcntrlMsg()
{
}

VWTcntrlMsg& VWTcntrlMsg::operator=(const VWTcntrlMsg& other)
{
    if (this==&other) return *this;
    ::ElectronicMessage::operator=(other);
    copy(other);
    return *this;
}

void VWTcntrlMsg::copy(const VWTcntrlMsg& other)
{
    this->wavelengths_var = other.wavelengths_var;
}

void VWTcntrlMsg::parsimPack(cCommBuffer *b)
{
    ::ElectronicMessage::parsimPack(b);
    doPacking(b,this->wavelengths_var);
}

void VWTcntrlMsg::parsimUnpack(cCommBuffer *b)
{
    ::ElectronicMessage::parsimUnpack(b);
    doUnpacking(b,this->wavelengths_var);
}

int VWTcntrlMsg::getWavelengths() const
{
    return wavelengths_var;
}

void VWTcntrlMsg::setWavelengths(int wavelengths)
{
    this->wavelengths_var = wavelengths;
}

class VWTcntrlMsgDescriptor : public cClassDescriptor
{
  public:
    VWTcntrlMsgDescriptor();
    virtual ~VWTcntrlMsgDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(VWTcntrlMsgDescriptor);

VWTcntrlMsgDescriptor::VWTcntrlMsgDescriptor() : cClassDescriptor("VWTcntrlMsg", "ElectronicMessage")
{
}

VWTcntrlMsgDescriptor::~VWTcntrlMsgDescriptor()
{
}

bool VWTcntrlMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<VWTcntrlMsg *>(obj)!=NULL;
}

const char *VWTcntrlMsgDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int VWTcntrlMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int VWTcntrlMsgDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *VWTcntrlMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "wavelengths",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int VWTcntrlMsgDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='w' && strcmp(fieldName, "wavelengths")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *VWTcntrlMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *VWTcntrlMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int VWTcntrlMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    VWTcntrlMsg *pp = (VWTcntrlMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string VWTcntrlMsgDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    VWTcntrlMsg *pp = (VWTcntrlMsg *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getWavelengths());
        default: return "";
    }
}

bool VWTcntrlMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    VWTcntrlMsg *pp = (VWTcntrlMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setWavelengths(string2long(value)); return true;
        default: return false;
    }
}

const char *VWTcntrlMsgDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *VWTcntrlMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    VWTcntrlMsg *pp = (VWTcntrlMsg *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(ApplicationData);

ApplicationData::ApplicationData(const char *name, int kind) : ::cPacket(name,kind)
{
    this->type_var = 0;
    this->id_var = 0;
    this->destId_var = 0;
    this->srcId_var = 0;
    this->payloadSize_var = 0;
    payload_arraysize = 0;
    this->payload_var = 0;
    this->isComplete_var = 0;
    this->creationTime_var = 0;
}

ApplicationData::ApplicationData(const ApplicationData& other) : ::cPacket(other)
{
    payload_arraysize = 0;
    this->payload_var = 0;
    copy(other);
}

ApplicationData::~ApplicationData()
{
    delete [] payload_var;
}

ApplicationData& ApplicationData::operator=(const ApplicationData& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void ApplicationData::copy(const ApplicationData& other)
{
    this->type_var = other.type_var;
    this->id_var = other.id_var;
    this->destId_var = other.destId_var;
    this->srcId_var = other.srcId_var;
    this->payloadSize_var = other.payloadSize_var;
    delete [] this->payload_var;
    this->payload_var = (other.payload_arraysize==0) ? NULL : new long[other.payload_arraysize];
    payload_arraysize = other.payload_arraysize;
    for (unsigned int i=0; i<payload_arraysize; i++)
        this->payload_var[i] = other.payload_var[i];
    this->isComplete_var = other.isComplete_var;
    this->creationTime_var = other.creationTime_var;
}

void ApplicationData::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->type_var);
    doPacking(b,this->id_var);
    doPacking(b,this->destId_var);
    doPacking(b,this->srcId_var);
    doPacking(b,this->payloadSize_var);
    b->pack(payload_arraysize);
    doPacking(b,this->payload_var,payload_arraysize);
    doPacking(b,this->isComplete_var);
    doPacking(b,this->creationTime_var);
}

void ApplicationData::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->type_var);
    doUnpacking(b,this->id_var);
    doUnpacking(b,this->destId_var);
    doUnpacking(b,this->srcId_var);
    doUnpacking(b,this->payloadSize_var);
    delete [] this->payload_var;
    b->unpack(payload_arraysize);
    if (payload_arraysize==0) {
        this->payload_var = 0;
    } else {
        this->payload_var = new long[payload_arraysize];
        doUnpacking(b,this->payload_var,payload_arraysize);
    }
    doUnpacking(b,this->isComplete_var);
    doUnpacking(b,this->creationTime_var);
}

int ApplicationData::getType() const
{
    return type_var;
}

void ApplicationData::setType(int type)
{
    this->type_var = type;
}

int ApplicationData::getId() const
{
    return id_var;
}

void ApplicationData::setId(int id)
{
    this->id_var = id;
}

int ApplicationData::getDestId() const
{
    return destId_var;
}

void ApplicationData::setDestId(int destId)
{
    this->destId_var = destId;
}

int ApplicationData::getSrcId() const
{
    return srcId_var;
}

void ApplicationData::setSrcId(int srcId)
{
    this->srcId_var = srcId;
}

int ApplicationData::getPayloadSize() const
{
    return payloadSize_var;
}

void ApplicationData::setPayloadSize(int payloadSize)
{
    this->payloadSize_var = payloadSize;
}

void ApplicationData::setPayloadArraySize(unsigned int size)
{
    long *payload_var2 = (size==0) ? NULL : new long[size];
    unsigned int sz = payload_arraysize < size ? payload_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        payload_var2[i] = this->payload_var[i];
    for (unsigned int i=sz; i<size; i++)
        payload_var2[i] = 0;
    payload_arraysize = size;
    delete [] this->payload_var;
    this->payload_var = payload_var2;
}

unsigned int ApplicationData::getPayloadArraySize() const
{
    return payload_arraysize;
}

long ApplicationData::getPayload(unsigned int k) const
{
    if (k>=payload_arraysize) throw cRuntimeError("Array of size %d indexed by %d", payload_arraysize, k);
    return payload_var[k];
}

void ApplicationData::setPayload(unsigned int k, long payload)
{
    if (k>=payload_arraysize) throw cRuntimeError("Array of size %d indexed by %d", payload_arraysize, k);
    this->payload_var[k] = payload;
}

bool ApplicationData::getIsComplete() const
{
    return isComplete_var;
}

void ApplicationData::setIsComplete(bool isComplete)
{
    this->isComplete_var = isComplete;
}

simtime_t ApplicationData::getCreationTime() const
{
    return creationTime_var;
}

void ApplicationData::setCreationTime(simtime_t creationTime)
{
    this->creationTime_var = creationTime;
}

class ApplicationDataDescriptor : public cClassDescriptor
{
  public:
    ApplicationDataDescriptor();
    virtual ~ApplicationDataDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(ApplicationDataDescriptor);

ApplicationDataDescriptor::ApplicationDataDescriptor() : cClassDescriptor("ApplicationData", "cPacket")
{
}

ApplicationDataDescriptor::~ApplicationDataDescriptor()
{
}

bool ApplicationDataDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<ApplicationData *>(obj)!=NULL;
}

const char *ApplicationDataDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int ApplicationDataDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount(object) : 8;
}

unsigned int ApplicationDataDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<8) ? fieldTypeFlags[field] : 0;
}

const char *ApplicationDataDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "type",
        "id",
        "destId",
        "srcId",
        "payloadSize",
        "payload",
        "isComplete",
        "creationTime",
    };
    return (field>=0 && field<8) ? fieldNames[field] : NULL;
}

int ApplicationDataDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+0;
    if (fieldName[0]=='i' && strcmp(fieldName, "id")==0) return base+1;
    if (fieldName[0]=='d' && strcmp(fieldName, "destId")==0) return base+2;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcId")==0) return base+3;
    if (fieldName[0]=='p' && strcmp(fieldName, "payloadSize")==0) return base+4;
    if (fieldName[0]=='p' && strcmp(fieldName, "payload")==0) return base+5;
    if (fieldName[0]=='i' && strcmp(fieldName, "isComplete")==0) return base+6;
    if (fieldName[0]=='c' && strcmp(fieldName, "creationTime")==0) return base+7;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *ApplicationDataDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
        "int",
        "int",
        "long",
        "bool",
        "simtime_t",
    };
    return (field>=0 && field<8) ? fieldTypeStrings[field] : NULL;
}

const char *ApplicationDataDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "ProcMsgType";
            return NULL;
        default: return NULL;
    }
}

int ApplicationDataDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    ApplicationData *pp = (ApplicationData *)object; (void)pp;
    switch (field) {
        case 5: return pp->getPayloadArraySize();
        default: return 0;
    }
}

std::string ApplicationDataDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    ApplicationData *pp = (ApplicationData *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getType());
        case 1: return long2string(pp->getId());
        case 2: return long2string(pp->getDestId());
        case 3: return long2string(pp->getSrcId());
        case 4: return long2string(pp->getPayloadSize());
        case 5: return long2string(pp->getPayload(i));
        case 6: return bool2string(pp->getIsComplete());
        case 7: return double2string(pp->getCreationTime());
        default: return "";
    }
}

bool ApplicationDataDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    ApplicationData *pp = (ApplicationData *)object; (void)pp;
    switch (field) {
        case 0: pp->setType(string2long(value)); return true;
        case 1: pp->setId(string2long(value)); return true;
        case 2: pp->setDestId(string2long(value)); return true;
        case 3: pp->setSrcId(string2long(value)); return true;
        case 4: pp->setPayloadSize(string2long(value)); return true;
        case 5: pp->setPayload(i,string2long(value)); return true;
        case 6: pp->setIsComplete(string2bool(value)); return true;
        case 7: pp->setCreationTime(string2double(value)); return true;
        default: return false;
    }
}

const char *ApplicationDataDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *ApplicationDataDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    ApplicationData *pp = (ApplicationData *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(ProcessorData);

ProcessorData::ProcessorData(const char *name, int kind) : ::cPacket(name,kind)
{
    this->size_var = 0;
    this->isComplete_var = 0;
    this->destAddr_var = 0;
    this->srcAddr_var = 0;
    this->type_var = 0;
    this->id_var = 0;
    this->creationTime_var = 0;
    this->nifArriveTime_var = 0;
    this->savedTime1_var = 0;
    this->savedTime2_var = 0;
    this->dataType_var = 0;
    this->switchPlanes_var = 0;
}

ProcessorData::ProcessorData(const ProcessorData& other) : ::cPacket(other)
{
    copy(other);
}

ProcessorData::~ProcessorData()
{
}

ProcessorData& ProcessorData::operator=(const ProcessorData& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void ProcessorData::copy(const ProcessorData& other)
{
    this->size_var = other.size_var;
    this->isComplete_var = other.isComplete_var;
    this->destAddr_var = other.destAddr_var;
    this->srcAddr_var = other.srcAddr_var;
    this->type_var = other.type_var;
    this->id_var = other.id_var;
    this->creationTime_var = other.creationTime_var;
    this->nifArriveTime_var = other.nifArriveTime_var;
    this->savedTime1_var = other.savedTime1_var;
    this->savedTime2_var = other.savedTime2_var;
    this->dataType_var = other.dataType_var;
    this->switchPlanes_var = other.switchPlanes_var;
}

void ProcessorData::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->size_var);
    doPacking(b,this->isComplete_var);
    doPacking(b,this->destAddr_var);
    doPacking(b,this->srcAddr_var);
    doPacking(b,this->type_var);
    doPacking(b,this->id_var);
    doPacking(b,this->creationTime_var);
    doPacking(b,this->nifArriveTime_var);
    doPacking(b,this->savedTime1_var);
    doPacking(b,this->savedTime2_var);
    doPacking(b,this->dataType_var);
    doPacking(b,this->switchPlanes_var);
}

void ProcessorData::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->size_var);
    doUnpacking(b,this->isComplete_var);
    doUnpacking(b,this->destAddr_var);
    doUnpacking(b,this->srcAddr_var);
    doUnpacking(b,this->type_var);
    doUnpacking(b,this->id_var);
    doUnpacking(b,this->creationTime_var);
    doUnpacking(b,this->nifArriveTime_var);
    doUnpacking(b,this->savedTime1_var);
    doUnpacking(b,this->savedTime2_var);
    doUnpacking(b,this->dataType_var);
    doUnpacking(b,this->switchPlanes_var);
}

int ProcessorData::getSize() const
{
    return size_var;
}

void ProcessorData::setSize(int size)
{
    this->size_var = size;
}

bool ProcessorData::getIsComplete() const
{
    return isComplete_var;
}

void ProcessorData::setIsComplete(bool isComplete)
{
    this->isComplete_var = isComplete;
}

long ProcessorData::getDestAddr() const
{
    return destAddr_var;
}

void ProcessorData::setDestAddr(long destAddr)
{
    this->destAddr_var = destAddr;
}

long ProcessorData::getSrcAddr() const
{
    return srcAddr_var;
}

void ProcessorData::setSrcAddr(long srcAddr)
{
    this->srcAddr_var = srcAddr;
}

int ProcessorData::getType() const
{
    return type_var;
}

void ProcessorData::setType(int type)
{
    this->type_var = type;
}

int ProcessorData::getId() const
{
    return id_var;
}

void ProcessorData::setId(int id)
{
    this->id_var = id;
}

simtime_t ProcessorData::getCreationTime() const
{
    return creationTime_var;
}

void ProcessorData::setCreationTime(simtime_t creationTime)
{
    this->creationTime_var = creationTime;
}

simtime_t ProcessorData::getNifArriveTime() const
{
    return nifArriveTime_var;
}

void ProcessorData::setNifArriveTime(simtime_t nifArriveTime)
{
    this->nifArriveTime_var = nifArriveTime;
}

simtime_t ProcessorData::getSavedTime1() const
{
    return savedTime1_var;
}

void ProcessorData::setSavedTime1(simtime_t savedTime1)
{
    this->savedTime1_var = savedTime1;
}

simtime_t ProcessorData::getSavedTime2() const
{
    return savedTime2_var;
}

void ProcessorData::setSavedTime2(simtime_t savedTime2)
{
    this->savedTime2_var = savedTime2;
}

int ProcessorData::getDataType() const
{
    return dataType_var;
}

void ProcessorData::setDataType(int dataType)
{
    this->dataType_var = dataType;
}

int ProcessorData::getSwitchPlanes() const
{
    return switchPlanes_var;
}

void ProcessorData::setSwitchPlanes(int switchPlanes)
{
    this->switchPlanes_var = switchPlanes;
}

class ProcessorDataDescriptor : public cClassDescriptor
{
  public:
    ProcessorDataDescriptor();
    virtual ~ProcessorDataDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(ProcessorDataDescriptor);

ProcessorDataDescriptor::ProcessorDataDescriptor() : cClassDescriptor("ProcessorData", "cPacket")
{
}

ProcessorDataDescriptor::~ProcessorDataDescriptor()
{
}

bool ProcessorDataDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<ProcessorData *>(obj)!=NULL;
}

const char *ProcessorDataDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int ProcessorDataDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 12+basedesc->getFieldCount(object) : 12;
}

unsigned int ProcessorDataDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<12) ? fieldTypeFlags[field] : 0;
}

const char *ProcessorDataDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "size",
        "isComplete",
        "destAddr",
        "srcAddr",
        "type",
        "id",
        "creationTime",
        "nifArriveTime",
        "savedTime1",
        "savedTime2",
        "dataType",
        "switchPlanes",
    };
    return (field>=0 && field<12) ? fieldNames[field] : NULL;
}

int ProcessorDataDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "size")==0) return base+0;
    if (fieldName[0]=='i' && strcmp(fieldName, "isComplete")==0) return base+1;
    if (fieldName[0]=='d' && strcmp(fieldName, "destAddr")==0) return base+2;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcAddr")==0) return base+3;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+4;
    if (fieldName[0]=='i' && strcmp(fieldName, "id")==0) return base+5;
    if (fieldName[0]=='c' && strcmp(fieldName, "creationTime")==0) return base+6;
    if (fieldName[0]=='n' && strcmp(fieldName, "nifArriveTime")==0) return base+7;
    if (fieldName[0]=='s' && strcmp(fieldName, "savedTime1")==0) return base+8;
    if (fieldName[0]=='s' && strcmp(fieldName, "savedTime2")==0) return base+9;
    if (fieldName[0]=='d' && strcmp(fieldName, "dataType")==0) return base+10;
    if (fieldName[0]=='s' && strcmp(fieldName, "switchPlanes")==0) return base+11;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *ProcessorDataDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "bool",
        "long",
        "long",
        "int",
        "int",
        "simtime_t",
        "simtime_t",
        "simtime_t",
        "simtime_t",
        "int",
        "int",
    };
    return (field>=0 && field<12) ? fieldTypeStrings[field] : NULL;
}

const char *ProcessorDataDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 4:
            if (!strcmp(propertyname,"enum")) return "ElectronicMessageTypes";
            return NULL;
        default: return NULL;
    }
}

int ProcessorDataDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    ProcessorData *pp = (ProcessorData *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string ProcessorDataDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    ProcessorData *pp = (ProcessorData *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getSize());
        case 1: return bool2string(pp->getIsComplete());
        case 2: return long2string(pp->getDestAddr());
        case 3: return long2string(pp->getSrcAddr());
        case 4: return long2string(pp->getType());
        case 5: return long2string(pp->getId());
        case 6: return double2string(pp->getCreationTime());
        case 7: return double2string(pp->getNifArriveTime());
        case 8: return double2string(pp->getSavedTime1());
        case 9: return double2string(pp->getSavedTime2());
        case 10: return long2string(pp->getDataType());
        case 11: return long2string(pp->getSwitchPlanes());
        default: return "";
    }
}

bool ProcessorDataDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    ProcessorData *pp = (ProcessorData *)object; (void)pp;
    switch (field) {
        case 0: pp->setSize(string2long(value)); return true;
        case 1: pp->setIsComplete(string2bool(value)); return true;
        case 2: pp->setDestAddr(string2long(value)); return true;
        case 3: pp->setSrcAddr(string2long(value)); return true;
        case 4: pp->setType(string2long(value)); return true;
        case 5: pp->setId(string2long(value)); return true;
        case 6: pp->setCreationTime(string2double(value)); return true;
        case 7: pp->setNifArriveTime(string2double(value)); return true;
        case 8: pp->setSavedTime1(string2double(value)); return true;
        case 9: pp->setSavedTime2(string2double(value)); return true;
        case 10: pp->setDataType(string2long(value)); return true;
        case 11: pp->setSwitchPlanes(string2long(value)); return true;
        default: return false;
    }
}

const char *ProcessorDataDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *ProcessorDataDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    ProcessorData *pp = (ProcessorData *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(RouterCntrlMsg);

RouterCntrlMsg::RouterCntrlMsg(const char *name, int kind) : ::cPacket(name,kind)
{
    this->type_var = 0;
    this->data_var = 0;
    this->vc_var = 0;
    this->msgId_var = 0;
    this->newVC_var = 0;
    this->time_var = 0;
    circuitAvailable_arraysize = 0;
    this->circuitAvailable_var = 0;
    circuitCheck_arraysize = 0;
    this->circuitCheck_var = 0;
    this->RTB_var = 0;
    this->LTB_var = 0;
    this->sourceBit_var = 1;
}

RouterCntrlMsg::RouterCntrlMsg(const RouterCntrlMsg& other) : ::cPacket(other)
{
    circuitAvailable_arraysize = 0;
    this->circuitAvailable_var = 0;
    circuitCheck_arraysize = 0;
    this->circuitCheck_var = 0;
    copy(other);
}

RouterCntrlMsg::~RouterCntrlMsg()
{
    delete [] circuitAvailable_var;
    delete [] circuitCheck_var;
}

RouterCntrlMsg& RouterCntrlMsg::operator=(const RouterCntrlMsg& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void RouterCntrlMsg::copy(const RouterCntrlMsg& other)
{
    this->type_var = other.type_var;
    this->data_var = other.data_var;
    this->vc_var = other.vc_var;
    this->msgId_var = other.msgId_var;
    this->newVC_var = other.newVC_var;
    this->time_var = other.time_var;
    delete [] this->circuitAvailable_var;
    this->circuitAvailable_var = (other.circuitAvailable_arraysize==0) ? NULL : new bool[other.circuitAvailable_arraysize];
    circuitAvailable_arraysize = other.circuitAvailable_arraysize;
    for (unsigned int i=0; i<circuitAvailable_arraysize; i++)
        this->circuitAvailable_var[i] = other.circuitAvailable_var[i];
    delete [] this->circuitCheck_var;
    this->circuitCheck_var = (other.circuitCheck_arraysize==0) ? NULL : new bool[other.circuitCheck_arraysize];
    circuitCheck_arraysize = other.circuitCheck_arraysize;
    for (unsigned int i=0; i<circuitCheck_arraysize; i++)
        this->circuitCheck_var[i] = other.circuitCheck_var[i];
    this->RTB_var = other.RTB_var;
    this->LTB_var = other.LTB_var;
    this->sourceBit_var = other.sourceBit_var;
}

void RouterCntrlMsg::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->type_var);
    doPacking(b,this->data_var);
    doPacking(b,this->vc_var);
    doPacking(b,this->msgId_var);
    doPacking(b,this->newVC_var);
    doPacking(b,this->time_var);
    b->pack(circuitAvailable_arraysize);
    doPacking(b,this->circuitAvailable_var,circuitAvailable_arraysize);
    b->pack(circuitCheck_arraysize);
    doPacking(b,this->circuitCheck_var,circuitCheck_arraysize);
    doPacking(b,this->RTB_var);
    doPacking(b,this->LTB_var);
    doPacking(b,this->sourceBit_var);
}

void RouterCntrlMsg::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->type_var);
    doUnpacking(b,this->data_var);
    doUnpacking(b,this->vc_var);
    doUnpacking(b,this->msgId_var);
    doUnpacking(b,this->newVC_var);
    doUnpacking(b,this->time_var);
    delete [] this->circuitAvailable_var;
    b->unpack(circuitAvailable_arraysize);
    if (circuitAvailable_arraysize==0) {
        this->circuitAvailable_var = 0;
    } else {
        this->circuitAvailable_var = new bool[circuitAvailable_arraysize];
        doUnpacking(b,this->circuitAvailable_var,circuitAvailable_arraysize);
    }
    delete [] this->circuitCheck_var;
    b->unpack(circuitCheck_arraysize);
    if (circuitCheck_arraysize==0) {
        this->circuitCheck_var = 0;
    } else {
        this->circuitCheck_var = new bool[circuitCheck_arraysize];
        doUnpacking(b,this->circuitCheck_var,circuitCheck_arraysize);
    }
    doUnpacking(b,this->RTB_var);
    doUnpacking(b,this->LTB_var);
    doUnpacking(b,this->sourceBit_var);
}

int RouterCntrlMsg::getType() const
{
    return type_var;
}

void RouterCntrlMsg::setType(int type)
{
    this->type_var = type;
}

long RouterCntrlMsg::getData() const
{
    return data_var;
}

void RouterCntrlMsg::setData(long data)
{
    this->data_var = data;
}

int RouterCntrlMsg::getVc() const
{
    return vc_var;
}

void RouterCntrlMsg::setVc(int vc)
{
    this->vc_var = vc;
}

int RouterCntrlMsg::getMsgId() const
{
    return msgId_var;
}

void RouterCntrlMsg::setMsgId(int msgId)
{
    this->msgId_var = msgId;
}

int RouterCntrlMsg::getNewVC() const
{
    return newVC_var;
}

void RouterCntrlMsg::setNewVC(int newVC)
{
    this->newVC_var = newVC;
}

simtime_t RouterCntrlMsg::getTime() const
{
    return time_var;
}

void RouterCntrlMsg::setTime(simtime_t time)
{
    this->time_var = time;
}

void RouterCntrlMsg::setCircuitAvailableArraySize(unsigned int size)
{
    bool *circuitAvailable_var2 = (size==0) ? NULL : new bool[size];
    unsigned int sz = circuitAvailable_arraysize < size ? circuitAvailable_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        circuitAvailable_var2[i] = this->circuitAvailable_var[i];
    for (unsigned int i=sz; i<size; i++)
        circuitAvailable_var2[i] = 0;
    circuitAvailable_arraysize = size;
    delete [] this->circuitAvailable_var;
    this->circuitAvailable_var = circuitAvailable_var2;
}

unsigned int RouterCntrlMsg::getCircuitAvailableArraySize() const
{
    return circuitAvailable_arraysize;
}

bool RouterCntrlMsg::getCircuitAvailable(unsigned int k) const
{
    if (k>=circuitAvailable_arraysize) throw cRuntimeError("Array of size %d indexed by %d", circuitAvailable_arraysize, k);
    return circuitAvailable_var[k];
}

void RouterCntrlMsg::setCircuitAvailable(unsigned int k, bool circuitAvailable)
{
    if (k>=circuitAvailable_arraysize) throw cRuntimeError("Array of size %d indexed by %d", circuitAvailable_arraysize, k);
    this->circuitAvailable_var[k] = circuitAvailable;
}

void RouterCntrlMsg::setCircuitCheckArraySize(unsigned int size)
{
    bool *circuitCheck_var2 = (size==0) ? NULL : new bool[size];
    unsigned int sz = circuitCheck_arraysize < size ? circuitCheck_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        circuitCheck_var2[i] = this->circuitCheck_var[i];
    for (unsigned int i=sz; i<size; i++)
        circuitCheck_var2[i] = 0;
    circuitCheck_arraysize = size;
    delete [] this->circuitCheck_var;
    this->circuitCheck_var = circuitCheck_var2;
}

unsigned int RouterCntrlMsg::getCircuitCheckArraySize() const
{
    return circuitCheck_arraysize;
}

bool RouterCntrlMsg::getCircuitCheck(unsigned int k) const
{
    if (k>=circuitCheck_arraysize) throw cRuntimeError("Array of size %d indexed by %d", circuitCheck_arraysize, k);
    return circuitCheck_var[k];
}

void RouterCntrlMsg::setCircuitCheck(unsigned int k, bool circuitCheck)
{
    if (k>=circuitCheck_arraysize) throw cRuntimeError("Array of size %d indexed by %d", circuitCheck_arraysize, k);
    this->circuitCheck_var[k] = circuitCheck;
}

int RouterCntrlMsg::getRTB() const
{
    return RTB_var;
}

void RouterCntrlMsg::setRTB(int RTB)
{
    this->RTB_var = RTB;
}

int RouterCntrlMsg::getLTB() const
{
    return LTB_var;
}

void RouterCntrlMsg::setLTB(int LTB)
{
    this->LTB_var = LTB;
}

int RouterCntrlMsg::getSourceBit() const
{
    return sourceBit_var;
}

void RouterCntrlMsg::setSourceBit(int sourceBit)
{
    this->sourceBit_var = sourceBit;
}

class RouterCntrlMsgDescriptor : public cClassDescriptor
{
  public:
    RouterCntrlMsgDescriptor();
    virtual ~RouterCntrlMsgDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(RouterCntrlMsgDescriptor);

RouterCntrlMsgDescriptor::RouterCntrlMsgDescriptor() : cClassDescriptor("RouterCntrlMsg", "cPacket")
{
}

RouterCntrlMsgDescriptor::~RouterCntrlMsgDescriptor()
{
}

bool RouterCntrlMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<RouterCntrlMsg *>(obj)!=NULL;
}

const char *RouterCntrlMsgDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int RouterCntrlMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 11+basedesc->getFieldCount(object) : 11;
}

unsigned int RouterCntrlMsgDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<11) ? fieldTypeFlags[field] : 0;
}

const char *RouterCntrlMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "type",
        "data",
        "vc",
        "msgId",
        "newVC",
        "time",
        "circuitAvailable",
        "circuitCheck",
        "RTB",
        "LTB",
        "sourceBit",
    };
    return (field>=0 && field<11) ? fieldNames[field] : NULL;
}

int RouterCntrlMsgDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "data")==0) return base+1;
    if (fieldName[0]=='v' && strcmp(fieldName, "vc")==0) return base+2;
    if (fieldName[0]=='m' && strcmp(fieldName, "msgId")==0) return base+3;
    if (fieldName[0]=='n' && strcmp(fieldName, "newVC")==0) return base+4;
    if (fieldName[0]=='t' && strcmp(fieldName, "time")==0) return base+5;
    if (fieldName[0]=='c' && strcmp(fieldName, "circuitAvailable")==0) return base+6;
    if (fieldName[0]=='c' && strcmp(fieldName, "circuitCheck")==0) return base+7;
    if (fieldName[0]=='R' && strcmp(fieldName, "RTB")==0) return base+8;
    if (fieldName[0]=='L' && strcmp(fieldName, "LTB")==0) return base+9;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceBit")==0) return base+10;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *RouterCntrlMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "long",
        "int",
        "int",
        "int",
        "simtime_t",
        "bool",
        "bool",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<11) ? fieldTypeStrings[field] : NULL;
}

const char *RouterCntrlMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "ElectronicMessageTypes";
            return NULL;
        default: return NULL;
    }
}

int RouterCntrlMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    RouterCntrlMsg *pp = (RouterCntrlMsg *)object; (void)pp;
    switch (field) {
        case 6: return pp->getCircuitAvailableArraySize();
        case 7: return pp->getCircuitCheckArraySize();
        default: return 0;
    }
}

std::string RouterCntrlMsgDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    RouterCntrlMsg *pp = (RouterCntrlMsg *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getType());
        case 1: return long2string(pp->getData());
        case 2: return long2string(pp->getVc());
        case 3: return long2string(pp->getMsgId());
        case 4: return long2string(pp->getNewVC());
        case 5: return double2string(pp->getTime());
        case 6: return bool2string(pp->getCircuitAvailable(i));
        case 7: return bool2string(pp->getCircuitCheck(i));
        case 8: return long2string(pp->getRTB());
        case 9: return long2string(pp->getLTB());
        case 10: return long2string(pp->getSourceBit());
        default: return "";
    }
}

bool RouterCntrlMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    RouterCntrlMsg *pp = (RouterCntrlMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setType(string2long(value)); return true;
        case 1: pp->setData(string2long(value)); return true;
        case 2: pp->setVc(string2long(value)); return true;
        case 3: pp->setMsgId(string2long(value)); return true;
        case 4: pp->setNewVC(string2long(value)); return true;
        case 5: pp->setTime(string2double(value)); return true;
        case 6: pp->setCircuitAvailable(i,string2bool(value)); return true;
        case 7: pp->setCircuitCheck(i,string2bool(value)); return true;
        case 8: pp->setRTB(string2long(value)); return true;
        case 9: pp->setLTB(string2long(value)); return true;
        case 10: pp->setSourceBit(string2long(value)); return true;
        default: return false;
    }
}

const char *RouterCntrlMsgDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *RouterCntrlMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    RouterCntrlMsg *pp = (RouterCntrlMsg *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(DeviceCntrlMsg);

DeviceCntrlMsg::DeviceCntrlMsg(const char *name, int kind) : ::cPacket(name,kind)
{
    this->on_var = 0;
    this->data_var = 0;
}

DeviceCntrlMsg::DeviceCntrlMsg(const DeviceCntrlMsg& other) : ::cPacket(other)
{
    copy(other);
}

DeviceCntrlMsg::~DeviceCntrlMsg()
{
}

DeviceCntrlMsg& DeviceCntrlMsg::operator=(const DeviceCntrlMsg& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void DeviceCntrlMsg::copy(const DeviceCntrlMsg& other)
{
    this->on_var = other.on_var;
    this->data_var = other.data_var;
}

void DeviceCntrlMsg::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->on_var);
    doPacking(b,this->data_var);
}

void DeviceCntrlMsg::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->on_var);
    doUnpacking(b,this->data_var);
}

bool DeviceCntrlMsg::getOn() const
{
    return on_var;
}

void DeviceCntrlMsg::setOn(bool on)
{
    this->on_var = on;
}

double DeviceCntrlMsg::getData() const
{
    return data_var;
}

void DeviceCntrlMsg::setData(double data)
{
    this->data_var = data;
}

class DeviceCntrlMsgDescriptor : public cClassDescriptor
{
  public:
    DeviceCntrlMsgDescriptor();
    virtual ~DeviceCntrlMsgDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(DeviceCntrlMsgDescriptor);

DeviceCntrlMsgDescriptor::DeviceCntrlMsgDescriptor() : cClassDescriptor("DeviceCntrlMsg", "cPacket")
{
}

DeviceCntrlMsgDescriptor::~DeviceCntrlMsgDescriptor()
{
}

bool DeviceCntrlMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<DeviceCntrlMsg *>(obj)!=NULL;
}

const char *DeviceCntrlMsgDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int DeviceCntrlMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int DeviceCntrlMsgDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *DeviceCntrlMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "on",
        "data",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int DeviceCntrlMsgDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='o' && strcmp(fieldName, "on")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "data")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *DeviceCntrlMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "double",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *DeviceCntrlMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int DeviceCntrlMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    DeviceCntrlMsg *pp = (DeviceCntrlMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string DeviceCntrlMsgDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    DeviceCntrlMsg *pp = (DeviceCntrlMsg *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getOn());
        case 1: return double2string(pp->getData());
        default: return "";
    }
}

bool DeviceCntrlMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    DeviceCntrlMsg *pp = (DeviceCntrlMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setOn(string2bool(value)); return true;
        case 1: pp->setData(string2double(value)); return true;
        default: return false;
    }
}

const char *DeviceCntrlMsgDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *DeviceCntrlMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    DeviceCntrlMsg *pp = (DeviceCntrlMsg *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(XbarMsg);

XbarMsg::XbarMsg(const char *name, int kind) : ::RouterCntrlMsg(name,kind)
{
    this->fromPort_var = 0;
    this->toPort_var = 0;
}

XbarMsg::XbarMsg(const XbarMsg& other) : ::RouterCntrlMsg(other)
{
    copy(other);
}

XbarMsg::~XbarMsg()
{
}

XbarMsg& XbarMsg::operator=(const XbarMsg& other)
{
    if (this==&other) return *this;
    ::RouterCntrlMsg::operator=(other);
    copy(other);
    return *this;
}

void XbarMsg::copy(const XbarMsg& other)
{
    this->fromPort_var = other.fromPort_var;
    this->toPort_var = other.toPort_var;
}

void XbarMsg::parsimPack(cCommBuffer *b)
{
    ::RouterCntrlMsg::parsimPack(b);
    doPacking(b,this->fromPort_var);
    doPacking(b,this->toPort_var);
}

void XbarMsg::parsimUnpack(cCommBuffer *b)
{
    ::RouterCntrlMsg::parsimUnpack(b);
    doUnpacking(b,this->fromPort_var);
    doUnpacking(b,this->toPort_var);
}

int XbarMsg::getFromPort() const
{
    return fromPort_var;
}

void XbarMsg::setFromPort(int fromPort)
{
    this->fromPort_var = fromPort;
}

int XbarMsg::getToPort() const
{
    return toPort_var;
}

void XbarMsg::setToPort(int toPort)
{
    this->toPort_var = toPort;
}

class XbarMsgDescriptor : public cClassDescriptor
{
  public:
    XbarMsgDescriptor();
    virtual ~XbarMsgDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(XbarMsgDescriptor);

XbarMsgDescriptor::XbarMsgDescriptor() : cClassDescriptor("XbarMsg", "RouterCntrlMsg")
{
}

XbarMsgDescriptor::~XbarMsgDescriptor()
{
}

bool XbarMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<XbarMsg *>(obj)!=NULL;
}

const char *XbarMsgDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int XbarMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int XbarMsgDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *XbarMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "fromPort",
        "toPort",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int XbarMsgDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='f' && strcmp(fieldName, "fromPort")==0) return base+0;
    if (fieldName[0]=='t' && strcmp(fieldName, "toPort")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *XbarMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *XbarMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int XbarMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    XbarMsg *pp = (XbarMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string XbarMsgDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    XbarMsg *pp = (XbarMsg *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getFromPort());
        case 1: return long2string(pp->getToPort());
        default: return "";
    }
}

bool XbarMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    XbarMsg *pp = (XbarMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setFromPort(string2long(value)); return true;
        case 1: pp->setToPort(string2long(value)); return true;
        default: return false;
    }
}

const char *XbarMsgDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *XbarMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    XbarMsg *pp = (XbarMsg *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(ArbiterRequestMsg);

ArbiterRequestMsg::ArbiterRequestMsg(const char *name, int kind) : ::RouterCntrlMsg(name,kind)
{
    this->dest_var = 0;
    this->src_var = 0;
    this->reqType_var = 0;
    this->portIn_var = 0;
    this->size_var = 0;
    this->data_var = 0;
    this->bcast_var = 0;
    this->stage_var = 0;
}

ArbiterRequestMsg::ArbiterRequestMsg(const ArbiterRequestMsg& other) : ::RouterCntrlMsg(other)
{
    copy(other);
}

ArbiterRequestMsg::~ArbiterRequestMsg()
{
}

ArbiterRequestMsg& ArbiterRequestMsg::operator=(const ArbiterRequestMsg& other)
{
    if (this==&other) return *this;
    ::RouterCntrlMsg::operator=(other);
    copy(other);
    return *this;
}

void ArbiterRequestMsg::copy(const ArbiterRequestMsg& other)
{
    this->dest_var = other.dest_var;
    this->src_var = other.src_var;
    this->reqType_var = other.reqType_var;
    this->portIn_var = other.portIn_var;
    this->size_var = other.size_var;
    this->data_var = other.data_var;
    this->bcast_var = other.bcast_var;
    this->stage_var = other.stage_var;
}

void ArbiterRequestMsg::parsimPack(cCommBuffer *b)
{
    ::RouterCntrlMsg::parsimPack(b);
    doPacking(b,this->dest_var);
    doPacking(b,this->src_var);
    doPacking(b,this->reqType_var);
    doPacking(b,this->portIn_var);
    doPacking(b,this->size_var);
    doPacking(b,this->data_var);
    doPacking(b,this->bcast_var);
    doPacking(b,this->stage_var);
}

void ArbiterRequestMsg::parsimUnpack(cCommBuffer *b)
{
    ::RouterCntrlMsg::parsimUnpack(b);
    doUnpacking(b,this->dest_var);
    doUnpacking(b,this->src_var);
    doUnpacking(b,this->reqType_var);
    doUnpacking(b,this->portIn_var);
    doUnpacking(b,this->size_var);
    doUnpacking(b,this->data_var);
    doUnpacking(b,this->bcast_var);
    doUnpacking(b,this->stage_var);
}

long ArbiterRequestMsg::getDest() const
{
    return dest_var;
}

void ArbiterRequestMsg::setDest(long dest)
{
    this->dest_var = dest;
}

long ArbiterRequestMsg::getSrc() const
{
    return src_var;
}

void ArbiterRequestMsg::setSrc(long src)
{
    this->src_var = src;
}

int ArbiterRequestMsg::getReqType() const
{
    return reqType_var;
}

void ArbiterRequestMsg::setReqType(int reqType)
{
    this->reqType_var = reqType;
}

int ArbiterRequestMsg::getPortIn() const
{
    return portIn_var;
}

void ArbiterRequestMsg::setPortIn(int portIn)
{
    this->portIn_var = portIn;
}

int ArbiterRequestMsg::getSize() const
{
    return size_var;
}

void ArbiterRequestMsg::setSize(int size)
{
    this->size_var = size;
}

long ArbiterRequestMsg::getData() const
{
    return data_var;
}

void ArbiterRequestMsg::setData(long data)
{
    this->data_var = data;
}

bool ArbiterRequestMsg::getBcast() const
{
    return bcast_var;
}

void ArbiterRequestMsg::setBcast(bool bcast)
{
    this->bcast_var = bcast;
}

int ArbiterRequestMsg::getStage() const
{
    return stage_var;
}

void ArbiterRequestMsg::setStage(int stage)
{
    this->stage_var = stage;
}

class ArbiterRequestMsgDescriptor : public cClassDescriptor
{
  public:
    ArbiterRequestMsgDescriptor();
    virtual ~ArbiterRequestMsgDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(ArbiterRequestMsgDescriptor);

ArbiterRequestMsgDescriptor::ArbiterRequestMsgDescriptor() : cClassDescriptor("ArbiterRequestMsg", "RouterCntrlMsg")
{
}

ArbiterRequestMsgDescriptor::~ArbiterRequestMsgDescriptor()
{
}

bool ArbiterRequestMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<ArbiterRequestMsg *>(obj)!=NULL;
}

const char *ArbiterRequestMsgDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int ArbiterRequestMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount(object) : 8;
}

unsigned int ArbiterRequestMsgDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<8) ? fieldTypeFlags[field] : 0;
}

const char *ArbiterRequestMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "dest",
        "src",
        "reqType",
        "portIn",
        "size",
        "data",
        "bcast",
        "stage",
    };
    return (field>=0 && field<8) ? fieldNames[field] : NULL;
}

int ArbiterRequestMsgDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='d' && strcmp(fieldName, "dest")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "src")==0) return base+1;
    if (fieldName[0]=='r' && strcmp(fieldName, "reqType")==0) return base+2;
    if (fieldName[0]=='p' && strcmp(fieldName, "portIn")==0) return base+3;
    if (fieldName[0]=='s' && strcmp(fieldName, "size")==0) return base+4;
    if (fieldName[0]=='d' && strcmp(fieldName, "data")==0) return base+5;
    if (fieldName[0]=='b' && strcmp(fieldName, "bcast")==0) return base+6;
    if (fieldName[0]=='s' && strcmp(fieldName, "stage")==0) return base+7;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *ArbiterRequestMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "long",
        "long",
        "int",
        "int",
        "int",
        "long",
        "bool",
        "int",
    };
    return (field>=0 && field<8) ? fieldTypeStrings[field] : NULL;
}

const char *ArbiterRequestMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 2:
            if (!strcmp(propertyname,"enum")) return "ElectronicMessageTypes";
            return NULL;
        default: return NULL;
    }
}

int ArbiterRequestMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    ArbiterRequestMsg *pp = (ArbiterRequestMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string ArbiterRequestMsgDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    ArbiterRequestMsg *pp = (ArbiterRequestMsg *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getDest());
        case 1: return long2string(pp->getSrc());
        case 2: return long2string(pp->getReqType());
        case 3: return long2string(pp->getPortIn());
        case 4: return long2string(pp->getSize());
        case 5: return long2string(pp->getData());
        case 6: return bool2string(pp->getBcast());
        case 7: return long2string(pp->getStage());
        default: return "";
    }
}

bool ArbiterRequestMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    ArbiterRequestMsg *pp = (ArbiterRequestMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setDest(string2long(value)); return true;
        case 1: pp->setSrc(string2long(value)); return true;
        case 2: pp->setReqType(string2long(value)); return true;
        case 3: pp->setPortIn(string2long(value)); return true;
        case 4: pp->setSize(string2long(value)); return true;
        case 5: pp->setData(string2long(value)); return true;
        case 6: pp->setBcast(string2bool(value)); return true;
        case 7: pp->setStage(string2long(value)); return true;
        default: return false;
    }
}

const char *ArbiterRequestMsgDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *ArbiterRequestMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    ArbiterRequestMsg *pp = (ArbiterRequestMsg *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(ElementControlMessage);

ElementControlMessage::ElementControlMessage(const char *name, int kind) : ::RouterCntrlMsg(name,kind)
{
    this->state_var = 0;
    this->PSEid_var = 0;
}

ElementControlMessage::ElementControlMessage(const ElementControlMessage& other) : ::RouterCntrlMsg(other)
{
    copy(other);
}

ElementControlMessage::~ElementControlMessage()
{
}

ElementControlMessage& ElementControlMessage::operator=(const ElementControlMessage& other)
{
    if (this==&other) return *this;
    ::RouterCntrlMsg::operator=(other);
    copy(other);
    return *this;
}

void ElementControlMessage::copy(const ElementControlMessage& other)
{
    this->state_var = other.state_var;
    this->PSEid_var = other.PSEid_var;
}

void ElementControlMessage::parsimPack(cCommBuffer *b)
{
    ::RouterCntrlMsg::parsimPack(b);
    doPacking(b,this->state_var);
    doPacking(b,this->PSEid_var);
}

void ElementControlMessage::parsimUnpack(cCommBuffer *b)
{
    ::RouterCntrlMsg::parsimUnpack(b);
    doUnpacking(b,this->state_var);
    doUnpacking(b,this->PSEid_var);
}

int ElementControlMessage::getState() const
{
    return state_var;
}

void ElementControlMessage::setState(int state)
{
    this->state_var = state;
}

int ElementControlMessage::getPSEid() const
{
    return PSEid_var;
}

void ElementControlMessage::setPSEid(int PSEid)
{
    this->PSEid_var = PSEid;
}

class ElementControlMessageDescriptor : public cClassDescriptor
{
  public:
    ElementControlMessageDescriptor();
    virtual ~ElementControlMessageDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(ElementControlMessageDescriptor);

ElementControlMessageDescriptor::ElementControlMessageDescriptor() : cClassDescriptor("ElementControlMessage", "RouterCntrlMsg")
{
}

ElementControlMessageDescriptor::~ElementControlMessageDescriptor()
{
}

bool ElementControlMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<ElementControlMessage *>(obj)!=NULL;
}

const char *ElementControlMessageDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int ElementControlMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int ElementControlMessageDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *ElementControlMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "state",
        "PSEid",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int ElementControlMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "state")==0) return base+0;
    if (fieldName[0]=='P' && strcmp(fieldName, "PSEid")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *ElementControlMessageDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *ElementControlMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "PSE_STATE";
            return NULL;
        default: return NULL;
    }
}

int ElementControlMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    ElementControlMessage *pp = (ElementControlMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string ElementControlMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    ElementControlMessage *pp = (ElementControlMessage *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getState());
        case 1: return long2string(pp->getPSEid());
        default: return "";
    }
}

bool ElementControlMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    ElementControlMessage *pp = (ElementControlMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setState(string2long(value)); return true;
        case 1: pp->setPSEid(string2long(value)); return true;
        default: return false;
    }
}

const char *ElementControlMessageDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *ElementControlMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    ElementControlMessage *pp = (ElementControlMessage *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(BufferAckMsg);

BufferAckMsg::BufferAckMsg(const char *name, int kind) : ::ElectronicMessage(name,kind)
{
}

BufferAckMsg::BufferAckMsg(const BufferAckMsg& other) : ::ElectronicMessage(other)
{
    copy(other);
}

BufferAckMsg::~BufferAckMsg()
{
}

BufferAckMsg& BufferAckMsg::operator=(const BufferAckMsg& other)
{
    if (this==&other) return *this;
    ::ElectronicMessage::operator=(other);
    copy(other);
    return *this;
}

void BufferAckMsg::copy(const BufferAckMsg& other)
{
}

void BufferAckMsg::parsimPack(cCommBuffer *b)
{
    ::ElectronicMessage::parsimPack(b);
}

void BufferAckMsg::parsimUnpack(cCommBuffer *b)
{
    ::ElectronicMessage::parsimUnpack(b);
}

class BufferAckMsgDescriptor : public cClassDescriptor
{
  public:
    BufferAckMsgDescriptor();
    virtual ~BufferAckMsgDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(BufferAckMsgDescriptor);

BufferAckMsgDescriptor::BufferAckMsgDescriptor() : cClassDescriptor("BufferAckMsg", "ElectronicMessage")
{
}

BufferAckMsgDescriptor::~BufferAckMsgDescriptor()
{
}

bool BufferAckMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<BufferAckMsg *>(obj)!=NULL;
}

const char *BufferAckMsgDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int BufferAckMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int BufferAckMsgDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *BufferAckMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int BufferAckMsgDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *BufferAckMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *BufferAckMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int BufferAckMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    BufferAckMsg *pp = (BufferAckMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string BufferAckMsgDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    BufferAckMsg *pp = (BufferAckMsg *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool BufferAckMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    BufferAckMsg *pp = (BufferAckMsg *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *BufferAckMsgDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *BufferAckMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    BufferAckMsg *pp = (BufferAckMsg *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(DRAM_CntrlMsg);

DRAM_CntrlMsg::DRAM_CntrlMsg(const char *name, int kind) : ::ProcessorData(name,kind)
{
    this->type_var = 0;
    this->row_var = 0;
    this->col_var = 0;
    this->bank_var = 0;
    this->burst_var = 0;
    this->writeEn_var = 0;
    this->lastAccess_var = 0;
    this->coreAddr_var = 0;
    this->creationTime_var = 0;
    this->data_var = 0;
}

DRAM_CntrlMsg::DRAM_CntrlMsg(const DRAM_CntrlMsg& other) : ::ProcessorData(other)
{
    copy(other);
}

DRAM_CntrlMsg::~DRAM_CntrlMsg()
{
}

DRAM_CntrlMsg& DRAM_CntrlMsg::operator=(const DRAM_CntrlMsg& other)
{
    if (this==&other) return *this;
    ::ProcessorData::operator=(other);
    copy(other);
    return *this;
}

void DRAM_CntrlMsg::copy(const DRAM_CntrlMsg& other)
{
    this->type_var = other.type_var;
    this->row_var = other.row_var;
    this->col_var = other.col_var;
    this->bank_var = other.bank_var;
    this->burst_var = other.burst_var;
    this->writeEn_var = other.writeEn_var;
    this->lastAccess_var = other.lastAccess_var;
    this->coreAddr_var = other.coreAddr_var;
    this->creationTime_var = other.creationTime_var;
    this->data_var = other.data_var;
}

void DRAM_CntrlMsg::parsimPack(cCommBuffer *b)
{
    ::ProcessorData::parsimPack(b);
    doPacking(b,this->type_var);
    doPacking(b,this->row_var);
    doPacking(b,this->col_var);
    doPacking(b,this->bank_var);
    doPacking(b,this->burst_var);
    doPacking(b,this->writeEn_var);
    doPacking(b,this->lastAccess_var);
    doPacking(b,this->coreAddr_var);
    doPacking(b,this->creationTime_var);
    doPacking(b,this->data_var);
}

void DRAM_CntrlMsg::parsimUnpack(cCommBuffer *b)
{
    ::ProcessorData::parsimUnpack(b);
    doUnpacking(b,this->type_var);
    doUnpacking(b,this->row_var);
    doUnpacking(b,this->col_var);
    doUnpacking(b,this->bank_var);
    doUnpacking(b,this->burst_var);
    doUnpacking(b,this->writeEn_var);
    doUnpacking(b,this->lastAccess_var);
    doUnpacking(b,this->coreAddr_var);
    doUnpacking(b,this->creationTime_var);
    doUnpacking(b,this->data_var);
}

int DRAM_CntrlMsg::getType() const
{
    return type_var;
}

void DRAM_CntrlMsg::setType(int type)
{
    this->type_var = type;
}

int DRAM_CntrlMsg::getRow() const
{
    return row_var;
}

void DRAM_CntrlMsg::setRow(int row)
{
    this->row_var = row;
}

int DRAM_CntrlMsg::getCol() const
{
    return col_var;
}

void DRAM_CntrlMsg::setCol(int col)
{
    this->col_var = col;
}

int DRAM_CntrlMsg::getBank() const
{
    return bank_var;
}

void DRAM_CntrlMsg::setBank(int bank)
{
    this->bank_var = bank;
}

int DRAM_CntrlMsg::getBurst() const
{
    return burst_var;
}

void DRAM_CntrlMsg::setBurst(int burst)
{
    this->burst_var = burst;
}

bool DRAM_CntrlMsg::getWriteEn() const
{
    return writeEn_var;
}

void DRAM_CntrlMsg::setWriteEn(bool writeEn)
{
    this->writeEn_var = writeEn;
}

bool DRAM_CntrlMsg::getLastAccess() const
{
    return lastAccess_var;
}

void DRAM_CntrlMsg::setLastAccess(bool lastAccess)
{
    this->lastAccess_var = lastAccess;
}

long DRAM_CntrlMsg::getCoreAddr() const
{
    return coreAddr_var;
}

void DRAM_CntrlMsg::setCoreAddr(long coreAddr)
{
    this->coreAddr_var = coreAddr;
}

simtime_t DRAM_CntrlMsg::getCreationTime() const
{
    return creationTime_var;
}

void DRAM_CntrlMsg::setCreationTime(simtime_t creationTime)
{
    this->creationTime_var = creationTime;
}

long DRAM_CntrlMsg::getData() const
{
    return data_var;
}

void DRAM_CntrlMsg::setData(long data)
{
    this->data_var = data;
}

class DRAM_CntrlMsgDescriptor : public cClassDescriptor
{
  public:
    DRAM_CntrlMsgDescriptor();
    virtual ~DRAM_CntrlMsgDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(DRAM_CntrlMsgDescriptor);

DRAM_CntrlMsgDescriptor::DRAM_CntrlMsgDescriptor() : cClassDescriptor("DRAM_CntrlMsg", "ProcessorData")
{
}

DRAM_CntrlMsgDescriptor::~DRAM_CntrlMsgDescriptor()
{
}

bool DRAM_CntrlMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<DRAM_CntrlMsg *>(obj)!=NULL;
}

const char *DRAM_CntrlMsgDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int DRAM_CntrlMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 10+basedesc->getFieldCount(object) : 10;
}

unsigned int DRAM_CntrlMsgDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<10) ? fieldTypeFlags[field] : 0;
}

const char *DRAM_CntrlMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "type",
        "row",
        "col",
        "bank",
        "burst",
        "writeEn",
        "lastAccess",
        "coreAddr",
        "creationTime",
        "data",
    };
    return (field>=0 && field<10) ? fieldNames[field] : NULL;
}

int DRAM_CntrlMsgDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "row")==0) return base+1;
    if (fieldName[0]=='c' && strcmp(fieldName, "col")==0) return base+2;
    if (fieldName[0]=='b' && strcmp(fieldName, "bank")==0) return base+3;
    if (fieldName[0]=='b' && strcmp(fieldName, "burst")==0) return base+4;
    if (fieldName[0]=='w' && strcmp(fieldName, "writeEn")==0) return base+5;
    if (fieldName[0]=='l' && strcmp(fieldName, "lastAccess")==0) return base+6;
    if (fieldName[0]=='c' && strcmp(fieldName, "coreAddr")==0) return base+7;
    if (fieldName[0]=='c' && strcmp(fieldName, "creationTime")==0) return base+8;
    if (fieldName[0]=='d' && strcmp(fieldName, "data")==0) return base+9;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *DRAM_CntrlMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
        "int",
        "int",
        "bool",
        "bool",
        "long",
        "simtime_t",
        "long",
    };
    return (field>=0 && field<10) ? fieldTypeStrings[field] : NULL;
}

const char *DRAM_CntrlMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "DRAM_CntrlTypes";
            return NULL;
        default: return NULL;
    }
}

int DRAM_CntrlMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    DRAM_CntrlMsg *pp = (DRAM_CntrlMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string DRAM_CntrlMsgDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    DRAM_CntrlMsg *pp = (DRAM_CntrlMsg *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getType());
        case 1: return long2string(pp->getRow());
        case 2: return long2string(pp->getCol());
        case 3: return long2string(pp->getBank());
        case 4: return long2string(pp->getBurst());
        case 5: return bool2string(pp->getWriteEn());
        case 6: return bool2string(pp->getLastAccess());
        case 7: return long2string(pp->getCoreAddr());
        case 8: return double2string(pp->getCreationTime());
        case 9: return long2string(pp->getData());
        default: return "";
    }
}

bool DRAM_CntrlMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    DRAM_CntrlMsg *pp = (DRAM_CntrlMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setType(string2long(value)); return true;
        case 1: pp->setRow(string2long(value)); return true;
        case 2: pp->setCol(string2long(value)); return true;
        case 3: pp->setBank(string2long(value)); return true;
        case 4: pp->setBurst(string2long(value)); return true;
        case 5: pp->setWriteEn(string2bool(value)); return true;
        case 6: pp->setLastAccess(string2bool(value)); return true;
        case 7: pp->setCoreAddr(string2long(value)); return true;
        case 8: pp->setCreationTime(string2double(value)); return true;
        case 9: pp->setData(string2long(value)); return true;
        default: return false;
    }
}

const char *DRAM_CntrlMsgDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *DRAM_CntrlMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    DRAM_CntrlMsg *pp = (DRAM_CntrlMsg *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(MemoryAccess);

MemoryAccess::MemoryAccess(const char *name, int kind) : ::ApplicationData(name,kind)
{
    this->addr_var = 0;
    this->dimm_var = 0;
    this->bank_var = 0;
    this->accessType_var = 0;
    this->threadId_var = 0;
    this->priority_var = 0;
    this->accessSize_var = 0;
}

MemoryAccess::MemoryAccess(const MemoryAccess& other) : ::ApplicationData(other)
{
    copy(other);
}

MemoryAccess::~MemoryAccess()
{
}

MemoryAccess& MemoryAccess::operator=(const MemoryAccess& other)
{
    if (this==&other) return *this;
    ::ApplicationData::operator=(other);
    copy(other);
    return *this;
}

void MemoryAccess::copy(const MemoryAccess& other)
{
    this->addr_var = other.addr_var;
    this->dimm_var = other.dimm_var;
    this->bank_var = other.bank_var;
    this->accessType_var = other.accessType_var;
    this->threadId_var = other.threadId_var;
    this->priority_var = other.priority_var;
    this->accessSize_var = other.accessSize_var;
}

void MemoryAccess::parsimPack(cCommBuffer *b)
{
    ::ApplicationData::parsimPack(b);
    doPacking(b,this->addr_var);
    doPacking(b,this->dimm_var);
    doPacking(b,this->bank_var);
    doPacking(b,this->accessType_var);
    doPacking(b,this->threadId_var);
    doPacking(b,this->priority_var);
    doPacking(b,this->accessSize_var);
}

void MemoryAccess::parsimUnpack(cCommBuffer *b)
{
    ::ApplicationData::parsimUnpack(b);
    doUnpacking(b,this->addr_var);
    doUnpacking(b,this->dimm_var);
    doUnpacking(b,this->bank_var);
    doUnpacking(b,this->accessType_var);
    doUnpacking(b,this->threadId_var);
    doUnpacking(b,this->priority_var);
    doUnpacking(b,this->accessSize_var);
}

long MemoryAccess::getAddr() const
{
    return addr_var;
}

void MemoryAccess::setAddr(long addr)
{
    this->addr_var = addr;
}

int MemoryAccess::getDimm() const
{
    return dimm_var;
}

void MemoryAccess::setDimm(int dimm)
{
    this->dimm_var = dimm;
}

int MemoryAccess::getBank() const
{
    return bank_var;
}

void MemoryAccess::setBank(int bank)
{
    this->bank_var = bank;
}

int MemoryAccess::getAccessType() const
{
    return accessType_var;
}

void MemoryAccess::setAccessType(int accessType)
{
    this->accessType_var = accessType;
}

int MemoryAccess::getThreadId() const
{
    return threadId_var;
}

void MemoryAccess::setThreadId(int threadId)
{
    this->threadId_var = threadId;
}

int MemoryAccess::getPriority() const
{
    return priority_var;
}

void MemoryAccess::setPriority(int priority)
{
    this->priority_var = priority;
}

int MemoryAccess::getAccessSize() const
{
    return accessSize_var;
}

void MemoryAccess::setAccessSize(int accessSize)
{
    this->accessSize_var = accessSize;
}

class MemoryAccessDescriptor : public cClassDescriptor
{
  public:
    MemoryAccessDescriptor();
    virtual ~MemoryAccessDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(MemoryAccessDescriptor);

MemoryAccessDescriptor::MemoryAccessDescriptor() : cClassDescriptor("MemoryAccess", "ApplicationData")
{
}

MemoryAccessDescriptor::~MemoryAccessDescriptor()
{
}

bool MemoryAccessDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MemoryAccess *>(obj)!=NULL;
}

const char *MemoryAccessDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MemoryAccessDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount(object) : 7;
}

unsigned int MemoryAccessDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *MemoryAccessDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "addr",
        "dimm",
        "bank",
        "accessType",
        "threadId",
        "priority",
        "accessSize",
    };
    return (field>=0 && field<7) ? fieldNames[field] : NULL;
}

int MemoryAccessDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='a' && strcmp(fieldName, "addr")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "dimm")==0) return base+1;
    if (fieldName[0]=='b' && strcmp(fieldName, "bank")==0) return base+2;
    if (fieldName[0]=='a' && strcmp(fieldName, "accessType")==0) return base+3;
    if (fieldName[0]=='t' && strcmp(fieldName, "threadId")==0) return base+4;
    if (fieldName[0]=='p' && strcmp(fieldName, "priority")==0) return base+5;
    if (fieldName[0]=='a' && strcmp(fieldName, "accessSize")==0) return base+6;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *MemoryAccessDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "long",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : NULL;
}

const char *MemoryAccessDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 3:
            if (!strcmp(propertyname,"enum")) return "MemoryAccessType";
            return NULL;
        default: return NULL;
    }
}

int MemoryAccessDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MemoryAccess *pp = (MemoryAccess *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string MemoryAccessDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    MemoryAccess *pp = (MemoryAccess *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getAddr());
        case 1: return long2string(pp->getDimm());
        case 2: return long2string(pp->getBank());
        case 3: return long2string(pp->getAccessType());
        case 4: return long2string(pp->getThreadId());
        case 5: return long2string(pp->getPriority());
        case 6: return long2string(pp->getAccessSize());
        default: return "";
    }
}

bool MemoryAccessDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MemoryAccess *pp = (MemoryAccess *)object; (void)pp;
    switch (field) {
        case 0: pp->setAddr(string2long(value)); return true;
        case 1: pp->setDimm(string2long(value)); return true;
        case 2: pp->setBank(string2long(value)); return true;
        case 3: pp->setAccessType(string2long(value)); return true;
        case 4: pp->setThreadId(string2long(value)); return true;
        case 5: pp->setPriority(string2long(value)); return true;
        case 6: pp->setAccessSize(string2long(value)); return true;
        default: return false;
    }
}

const char *MemoryAccessDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *MemoryAccessDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MemoryAccess *pp = (MemoryAccess *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


