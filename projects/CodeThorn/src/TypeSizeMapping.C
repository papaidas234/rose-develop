#include "sage3basic.h"
#include "TypeSizeMapping.h"
#include "SprayException.h"

namespace SPRAY {
  
  void TypeSizeMapping::setMapping(std::vector<SPRAY::TypeSize> mapping) {
    if(_mapping.size()==0 || mapping.size()==_mapping.size()) {
      _mapping=mapping;
    } else {
      throw SPRAY::Exception("TypeSizeMapping: wrong number of type-size mapping values.");
    }
  }
  
  void TypeSizeMapping::setTypeSize(BuiltInType bitype, SPRAY::TypeSize size) {
    ROSE_ASSERT(bitype<_mapping.size());
    _mapping[bitype]=size;
  }
  
  SPRAY::TypeSize TypeSizeMapping::getTypeSize(BuiltInType bitype) {
    ROSE_ASSERT(bitype<_mapping.size());
    return _mapping[bitype];
  }

  std::size_t TypeSizeMapping::sizeOfOp(BuiltInType bitype) {
    ROSE_ASSERT(bitype<_mapping.size());
    return getTypeSize(bitype);
  }
  
  bool TypeSizeMapping::isCpp11StandardCompliant() {
    size_t byteSize=1;
    return byteSize==sizeOfOp(BITYPE_SCHAR)
      && sizeOfOp(BITYPE_SCHAR)<=sizeOfOp(BITYPE_SSHORT)
      && sizeOfOp(BITYPE_SSHORT)<=sizeOfOp(BITYPE_SINT)
      && sizeOfOp(BITYPE_SINT)<=sizeOfOp(BITYPE_SLONG)
      && sizeOfOp(BITYPE_SLONG)<=sizeOfOp(BITYPE_SLONG_LONG);
  }
  
} // end of namespace SPRAY
