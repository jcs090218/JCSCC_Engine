#ifndef __JAYCES_PLATFORMMACROS_H__
/**
 * $File: JayCeS_PlatformMacros.h $
 * $Date: 2016-12-27 02:35:47 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2016 by Shen, Jen-Chieh $
 */
#define __JAYCES_PLATFORMMACROS_H__


 /// @name namespace cocos2d
 /// @{
#ifdef __cplusplus
#define NS_JCSCC_BEGIN                     namespace jcscc {
#define NS_JCSCC_END                       }
#define USING_NS_JCSCC                     using namespace jcscc
#define NS_JCSCC                           ::jcscc
#else
#define NS_JCSCC_BEGIN 
#define NS_JCSCC_END 
#define USING_NS_JCSCC 
#define NS_JCSCC
#endif 
 //  end of namespace group
 /// @}

#define JCSCC_SAFE_DELETE(p)           do { delete (p); (p) = nullptr; } while(0)
#define JCSCC_SAFE_DELETE_ARRAY(p)     do { if(p) { delete[] (p); (p) = nullptr; } } while(0)
#define JCSCC_SAFE_FREE(p)             do { if(p) { free(p); (p) = nullptr; } } while(0)
#define JCSCC_SAFE_RELEASE(p)          do { if(p) { (p)->release(); } } while(0)
#define JCSCC_SAFE_RELEASE_NULL(p)     do { if(p) { (p)->release(); (p) = nullptr; } } while(0)
#define JCSCC_SAFE_RETAIN(p)           do { if(p) { (p)->retain(); } } while(0)
#define JCSCC_BREAK_IF(cond)           if(cond) break

 /// @name JCSCC debug
 /// @{
#if !defined(JCSCC_DEBUG) || JCSCC_DEBUG == 0
#define JCSCC_LOG(...)       do {} while (0)
#define JCSCC_LOGINFO(...)   do {} while (0)
#define JCSCC_LOGERROR(...)  do {} while (0)
#define JCSCC_LOGWARN(...)   do {} while (0)

#elif JCSCC_DEBUG == 1
#define JCSCC_LOG(format, ...)      jcscc::log(format, ##__VA_ARGS__)
#define JCSCC_LOGERROR(format,...)  jcscc::log(format, ##__VA_ARGS__)
#define JCSCC_LOGINFO(format,...)   do {} while (0)
#define JCSCC_LOGWARN(...) __JCSCCLOGWITHFUNCTION(__VA_ARGS__)

#elif JCSCC_DEBUG > 1
#define JCSCC_LOG(format, ...)      jcscc::log(format, ##__VA_ARGS__)
#define JCSCC_LOGERROR(format,...)  jcscc::log(format, ##__VA_ARGS__)
#define JCSCC_LOGINFO(format,...)   jcscc::log(format, ##__VA_ARGS__)
#define JCSCC_LOGWARN(...) __JCSCCLOGWITHFUNCTION(__VA_ARGS__)
#endif // JCSCC_DEBUG

 /** Lua engine debug */
#if !defined(JCSCC_DEBUG) || JCSCC_DEBUG == 0 || CC_LUA_ENGINE_DEBUG == 0
#define LUA_LOG(...)
#else
#define LUA_LOG(format, ...)     jcscc::log(format, ##__VA_ARGS__)
#endif // Lua engine debug

 //  end of debug group
 /// @}

/** @def JCSCC_DISALLOW_COPY_AND_ASSIGN(TypeName)
 * A macro to disallow the copy constructor and operator= functions.
 * This should be used in the private: declarations for a class
 */
#if defined(__GNUC__) && ((__GNUC__ >= 5) || ((__GNUG__ == 4) && (__GNUC_MINOR__ >= 4))) \
    || (defined(__clang__) && (__clang_major__ >= 3)) || (_MSC_VER >= 1800)
#define JCSCC_DISALLOW_COPY_AND_ASSIGN(TypeName)        \
    TypeName(const TypeName &) = delete;                \
    TypeName &operator =(const TypeName &) = delete;
#else
#define JCSCC_DISALLOW_COPY_AND_ASSIGN(TypeName)    \
    TypeName(const TypeName &);                     \
    TypeName &operator =(const TypeName &);
#endif

 /** @def JCSCC_DISALLOW_IMPLICIT_CONSTRUCTORS(TypeName)
  * A macro to disallow all the implicit constructors, namely the
  * default constructor, copy constructor and operator= functions.
  *
  * This should be used in the private: declarations for a class
  * that wants to prevent anyone from instantiating it. This is
  * especially useful for classes containing only static methods.
  */
#define JCSCC_DISALLOW_IMPLICIT_CONSTRUCTORS(TypeName)  \
    TypeName();                                         \
    JCSCC_DISALLOW_COPY_AND_ASSIGN(TypeName)

  /** @def JCSCC_DEPRECATED_ATTRIBUTE
   * Only certain compilers support __attribute__((deprecated)).
   */
#if defined(__GNUC__) && ((__GNUC__ >= 4) || ((__GNUC__ == 3) && (__GNUC_MINOR__ >= 1)))
#define JCSCC_DEPRECATED_ATTRIBUTE __attribute__((deprecated))
#elif _MSC_VER >= 1400 //vs 2005 or higher
#define JCSCC_DEPRECATED_ATTRIBUTE __declspec(deprecated)
#else
#define JCSCC_DEPRECATED_ATTRIBUTE
#endif

   /** @def JCSCC_DEPRECATED(...)
    * Macro to mark things deprecated as of a particular version
    * can be used with arbitrary parameters which are thrown away.
    * e.g. JCSCC_DEPRECATED(4.0) or JCSCC_DEPRECATED(4.0, "not going to need this anymore") etc.
    */
#define JCSCC_DEPRECATED(...) JCSCC_DEPRECATED_ATTRIBUTE

#ifdef __GNUC__
#define CC_UNUSED __attribute__ ((unused))
#else
#define CC_UNUSED
#endif

    /** @def JCSCC_REQUIRES_NULL_TERMINATION
     *
     */
#if !defined(JCSCC_REQUIRES_NULL_TERMINATION)
#if defined(__APPLE_CC__) && (__APPLE_CC__ >= 5549)
#define JCSCC_REQUIRES_NULL_TERMINATION __attribute__((sentinel(0,1)))
#elif defined(__GNUC__)
#define JCSCC_REQUIRES_NULL_TERMINATION __attribute__((sentinel))
#else
#define JCSCC_REQUIRES_NULL_TERMINATION
#endif
#endif

#endif // __JAYCES_PLATFORMMACROS_H__
