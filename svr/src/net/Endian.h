#ifndef Endian_h__
#define Endian_h__

#include <boost/cstdint.hpp>

using namespace boost;

namespace endian
{
    // ��64λ�������������ֽ�˳��ת���������ֽ�˳��
    uint64_t hostToNetwork64(uint64_t host64);

    // ��32λ�������������ֽ�˳��ת���������ֽ�˳��
    uint32_t hostToNetwork32(uint32_t host32);

    // ��16λ�������������ֽ�˳��ת���������ֽ�˳��
    uint16_t hostToNetwork16(uint16_t host16);

    // ��64λ�������������ֽ�˳��ת���������ֽ�˳��
    uint64_t networkToHost64(uint64_t net64);

    // ��32λ�������������ֽ�˳��ת���������ֽ�˳��
    uint32_t networkToHost32(uint32_t net32);

    // ��16λ�������������ֽ�˳��ת���������ֽ�˳��
    uint16_t networkToHost16(uint16_t net16);
}

#endif // Endian_h__
