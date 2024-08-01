//
// Generated file, do not edit! Created by opp_msgtool 6.0 from application/EthernetDataFrames.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include <type_traits>
#include "EthernetDataFrames_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

namespace inet {

Register_Class(EthernetDataPayload)

EthernetDataPayload::EthernetDataPayload() : ::inet::FieldsChunk()
{
}

EthernetDataPayload::EthernetDataPayload(const EthernetDataPayload& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

EthernetDataPayload::~EthernetDataPayload()
{
}

EthernetDataPayload& EthernetDataPayload::operator=(const EthernetDataPayload& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void EthernetDataPayload::copy(const EthernetDataPayload& other)
{
    this->frame_num = other.frame_num;
    this->burst_size = other.burst_size;
    this->genTime = other.genTime;
}

void EthernetDataPayload::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->frame_num);
    doParsimPacking(b,this->burst_size);
    doParsimPacking(b,this->genTime);
}

void EthernetDataPayload::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->frame_num);
    doParsimUnpacking(b,this->burst_size);
    doParsimUnpacking(b,this->genTime);
}

int EthernetDataPayload::getFrame_num() const
{
    return this->frame_num;
}

void EthernetDataPayload::setFrame_num(int frame_num)
{
    handleChange();
    this->frame_num = frame_num;
}

int EthernetDataPayload::getBurst_size() const
{
    return this->burst_size;
}

void EthernetDataPayload::setBurst_size(int burst_size)
{
    handleChange();
    this->burst_size = burst_size;
}

::omnetpp::simtime_t EthernetDataPayload::getGenTime() const
{
    return this->genTime;
}

void EthernetDataPayload::setGenTime(::omnetpp::simtime_t genTime)
{
    handleChange();
    this->genTime = genTime;
}

class EthernetDataPayloadDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_frame_num,
        FIELD_burst_size,
        FIELD_genTime,
    };
  public:
    EthernetDataPayloadDescriptor();
    virtual ~EthernetDataPayloadDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(EthernetDataPayloadDescriptor)

EthernetDataPayloadDescriptor::EthernetDataPayloadDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::EthernetDataPayload)), "inet::FieldsChunk")
{
    propertyNames = nullptr;
}

EthernetDataPayloadDescriptor::~EthernetDataPayloadDescriptor()
{
    delete[] propertyNames;
}

bool EthernetDataPayloadDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<EthernetDataPayload *>(obj)!=nullptr;
}

const char **EthernetDataPayloadDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *EthernetDataPayloadDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int EthernetDataPayloadDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int EthernetDataPayloadDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_frame_num
        FD_ISEDITABLE,    // FIELD_burst_size
        FD_ISEDITABLE,    // FIELD_genTime
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *EthernetDataPayloadDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "frame_num",
        "burst_size",
        "genTime",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int EthernetDataPayloadDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "frame_num") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "burst_size") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "genTime") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *EthernetDataPayloadDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_frame_num
        "int",    // FIELD_burst_size
        "omnetpp::simtime_t",    // FIELD_genTime
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **EthernetDataPayloadDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *EthernetDataPayloadDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int EthernetDataPayloadDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    EthernetDataPayload *pp = omnetpp::fromAnyPtr<EthernetDataPayload>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void EthernetDataPayloadDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    EthernetDataPayload *pp = omnetpp::fromAnyPtr<EthernetDataPayload>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'EthernetDataPayload'", field);
    }
}

const char *EthernetDataPayloadDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    EthernetDataPayload *pp = omnetpp::fromAnyPtr<EthernetDataPayload>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string EthernetDataPayloadDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    EthernetDataPayload *pp = omnetpp::fromAnyPtr<EthernetDataPayload>(object); (void)pp;
    switch (field) {
        case FIELD_frame_num: return long2string(pp->getFrame_num());
        case FIELD_burst_size: return long2string(pp->getBurst_size());
        case FIELD_genTime: return simtime2string(pp->getGenTime());
        default: return "";
    }
}

void EthernetDataPayloadDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    EthernetDataPayload *pp = omnetpp::fromAnyPtr<EthernetDataPayload>(object); (void)pp;
    switch (field) {
        case FIELD_frame_num: pp->setFrame_num(string2long(value)); break;
        case FIELD_burst_size: pp->setBurst_size(string2long(value)); break;
        case FIELD_genTime: pp->setGenTime(string2simtime(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EthernetDataPayload'", field);
    }
}

omnetpp::cValue EthernetDataPayloadDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    EthernetDataPayload *pp = omnetpp::fromAnyPtr<EthernetDataPayload>(object); (void)pp;
    switch (field) {
        case FIELD_frame_num: return pp->getFrame_num();
        case FIELD_burst_size: return pp->getBurst_size();
        case FIELD_genTime: return pp->getGenTime().dbl();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'EthernetDataPayload' as cValue -- field index out of range?", field);
    }
}

void EthernetDataPayloadDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    EthernetDataPayload *pp = omnetpp::fromAnyPtr<EthernetDataPayload>(object); (void)pp;
    switch (field) {
        case FIELD_frame_num: pp->setFrame_num(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_burst_size: pp->setBurst_size(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_genTime: pp->setGenTime(value.doubleValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EthernetDataPayload'", field);
    }
}

const char *EthernetDataPayloadDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr EthernetDataPayloadDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    EthernetDataPayload *pp = omnetpp::fromAnyPtr<EthernetDataPayload>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void EthernetDataPayloadDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    EthernetDataPayload *pp = omnetpp::fromAnyPtr<EthernetDataPayload>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'EthernetDataPayload'", field);
    }
}

Register_Class(TSNBindCommand)

TSNBindCommand::TSNBindCommand() : ::inet::SocketBindCommand()
{
}

TSNBindCommand::TSNBindCommand(const TSNBindCommand& other) : ::inet::SocketBindCommand(other)
{
    copy(other);
}

TSNBindCommand::~TSNBindCommand()
{
}

TSNBindCommand& TSNBindCommand::operator=(const TSNBindCommand& other)
{
    if (this == &other) return *this;
    ::inet::SocketBindCommand::operator=(other);
    copy(other);
    return *this;
}

void TSNBindCommand::copy(const TSNBindCommand& other)
{
    this->flowName = other.flowName;
}

void TSNBindCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::SocketBindCommand::parsimPack(b);
    doParsimPacking(b,this->flowName);
}

void TSNBindCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::SocketBindCommand::parsimUnpack(b);
    doParsimUnpacking(b,this->flowName);
}

const char * TSNBindCommand::getFlowName() const
{
    return this->flowName.c_str();
}

void TSNBindCommand::setFlowName(const char * flowName)
{
    this->flowName = flowName;
}

class TSNBindCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_flowName,
    };
  public:
    TSNBindCommandDescriptor();
    virtual ~TSNBindCommandDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(TSNBindCommandDescriptor)

TSNBindCommandDescriptor::TSNBindCommandDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::TSNBindCommand)), "inet::SocketBindCommand")
{
    propertyNames = nullptr;
}

TSNBindCommandDescriptor::~TSNBindCommandDescriptor()
{
    delete[] propertyNames;
}

bool TSNBindCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TSNBindCommand *>(obj)!=nullptr;
}

const char **TSNBindCommandDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *TSNBindCommandDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int TSNBindCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 1+base->getFieldCount() : 1;
}

unsigned int TSNBindCommandDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_flowName
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *TSNBindCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "flowName",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int TSNBindCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "flowName") == 0) return baseIndex + 0;
    return base ? base->findField(fieldName) : -1;
}

const char *TSNBindCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",    // FIELD_flowName
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **TSNBindCommandDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *TSNBindCommandDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int TSNBindCommandDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    TSNBindCommand *pp = omnetpp::fromAnyPtr<TSNBindCommand>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void TSNBindCommandDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    TSNBindCommand *pp = omnetpp::fromAnyPtr<TSNBindCommand>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'TSNBindCommand'", field);
    }
}

const char *TSNBindCommandDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    TSNBindCommand *pp = omnetpp::fromAnyPtr<TSNBindCommand>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TSNBindCommandDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    TSNBindCommand *pp = omnetpp::fromAnyPtr<TSNBindCommand>(object); (void)pp;
    switch (field) {
        case FIELD_flowName: return oppstring2string(pp->getFlowName());
        default: return "";
    }
}

void TSNBindCommandDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    TSNBindCommand *pp = omnetpp::fromAnyPtr<TSNBindCommand>(object); (void)pp;
    switch (field) {
        case FIELD_flowName: pp->setFlowName((value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'TSNBindCommand'", field);
    }
}

omnetpp::cValue TSNBindCommandDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    TSNBindCommand *pp = omnetpp::fromAnyPtr<TSNBindCommand>(object); (void)pp;
    switch (field) {
        case FIELD_flowName: return pp->getFlowName();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'TSNBindCommand' as cValue -- field index out of range?", field);
    }
}

void TSNBindCommandDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    TSNBindCommand *pp = omnetpp::fromAnyPtr<TSNBindCommand>(object); (void)pp;
    switch (field) {
        case FIELD_flowName: pp->setFlowName(value.stringValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'TSNBindCommand'", field);
    }
}

const char *TSNBindCommandDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr TSNBindCommandDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    TSNBindCommand *pp = omnetpp::fromAnyPtr<TSNBindCommand>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void TSNBindCommandDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    TSNBindCommand *pp = omnetpp::fromAnyPtr<TSNBindCommand>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'TSNBindCommand'", field);
    }
}

}  // namespace inet

namespace omnetpp {

}  // namespace omnetpp

