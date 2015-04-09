
#ifndef SDMATH_H
#define SDMATH_H
/**
* @file sdmath.h
* @brief ��ѧ������
*
**/
namespace SGDP
{
    /**
    * @defgroup ȡ�����Сֵ
    * @ingroup  SGDP
    * @{
    */

    /**
    * @brief
    * �Ƚ��������ݣ�������Сֵ
    * @param const T & __a ,const T & __b : ���бȽϵ�����ֵ
    * @return  T &  : ������Сֵ
    */
    template<typename T >
    inline const T SDMin(const T & __a, const T & __b)
    {
        return (__b < __a ) ? __b: __a;
    }

    /**
    * @brief
    * �Ƚ��������ݣ��������ֵ
    * @param const T & __a ,const T & __b : ���бȽϵ�����ֵ
    * @return T &  : �������ֵ
    */
    template<typename T >
    inline const T SDMax(const T & __a, const T & __b)
    {
        return (__a < __b)? __b : __a;
    }

    /** @} */

} //namespace SGDP

#endif // 


