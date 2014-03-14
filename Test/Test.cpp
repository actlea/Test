// Test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#pragma region 结构体的定义
struct C000
{
};

struct C010
{
C010() : c_(0x01) {}
void foo() { c_ = 0x02; }
char c_;
};

struct C011
{
C011() : c1_(0x02), c2_(0x03) {}
char c1_;
char c2_;
};

struct C012
{
static int sfoo() { return 1; }
int foo() { return 1; }
char c_;
static int i_;
};
int C012::i_ = 1;

//struct C013 : public C010
struct C013 : public C012
{
C013() : c1_(0x01) {}
void foo() { c1_ = 0x02; }
char c1_;
};

struct C014 : private C011
{
};

struct C015 : public C010, private C011
{
};

struct C016 : C015
{
C016() : i_(1) {}
int i_;
};

struct C020 : public virtual C010
{
C020() : c_(0x02) {}
char c_;
};

struct C021 : public virtual C010
{
C021() : c_(0x03) {}
char c_;
};

struct C030 : public C020, public C021
{
C030() : c_(0x04) {}
char c_;
};

struct C040
{
virtual void foo() {}
};

struct C041
{
C041() : c_(0x01) {}
virtual void foo() { c_ = 0x02; }
char c_;
};

struct C042
{
C042() : c_(0x02) {}
virtual void foo2() {}
char c_;
};

struct C043
{
virtual void foo1() {}
virtual void foo2() {}
};

struct C050 : C040
{
};

struct C051 : public C041, public C042
{
};

struct C071 : C043
{
virtual void foo1() {}
};

struct C082 : public C041, public C042
{
C082() : c_(0x03) {}
virtual void foo() {}
virtual void foo2() {}
virtual void foo3() {}
char c_;
};

struct C100 : public virtual C041
{
C100() : c_(0x02) {}
char c_;
};

struct C101 : public virtual C041
{
C101() : c_(0x03) {}
char c_;
};

struct C110 : public C100, public C101
{
C110() : c_(0x04) {}
char c_;
};

struct C140 : public virtual C041
{
C140() : c_(0x02) {}
virtual void foo() { c_ = 0x11; }
char c_;
};

struct C141 : public virtual C041
{
C141() : c_(0x03) {}
virtual void foo() { c_ = 0x12; }
char c_;
};

struct C150 : public C140, public C141
{
C150() : c_(0x04) {}
virtual void foo() { c_ = 0x21; }
char c_;
};

struct C160 : public virtual C041
{
C160() : c_(0x02) {}
virtual void foo() { c_ = 0x12; }
virtual void f160() { c_ = 0x12; }
char c_;
};

struct C161 : public virtual C041
{
C161() : c_(0x03) {}
virtual void foo() { c_ = 0x13; }
virtual void f161() { c_ = 0x13; }
char c_;
};

struct C170 : public C160, public C161
{
C170() : c_(0x04) {}
virtual void foo() { c_ = 0x14; }
virtual void f170() { c_ = 0x14; }
char c_;
};
# pragma endregion

#pragma region 函数的定义

//PRINT_SIZE
#define  PRINT_SIZE(CLASS_NAME) \
cout << "The size of " << #CLASS_NAME << " is " << sizeof(CLASS_NAME) << endl;

//PRINT_DETAIL
#define PRINT_DETAIL(CLASS_NAME, OBJECT_NAME) \
cout << "The detail of " << #CLASS_NAME << " is "; \
for (int i = 0; i < sizeof(OBJECT_NAME); ++i) { \
cout.fill('0'); \
cout << setw(2) << hex << ((short)((char*)(&(OBJECT_NAME)))[i] & 0x00ff); \
cout << ' '; } \
cout << setw(0) << dec << endl;

//PRINT_SIZE_DETAIL
#define PRINT_SIZE_DETAIL(CLASS_NAME) \
PRINT_SIZE(CLASS_NAME) \
CLASS_NAME _##CLASS_NAME; \
PRINT_DETAIL(CLASS_NAME, _##CLASS_NAME)

//LF
#define LF \
cout << endl;

//对象的内存地址
template<class T>
void *
get_obj_addr(const T & obj)
{
return (void*)&obj;
}

//虚表指针地址,start表示对象的内存地址
void *
get_vp_addr(void * start, int offset)
{
return (void*)((char*)start + offset);
}
//虚表的地址
void *
get_vt_addr(void * vp)
{
return (void*)*((void**)vp);
}
//虚表中条目的值
void *
get_vti_val(void * vt, int idx)
{
return (void*)*((void**)((int*)vt + idx));
}

//PRINT_VTABLE_ITEM
#define PRINT_VTABLE_ITEM(OBJ, VPOFFSET, INDEX) \
{ \
cout.fill(' '); \
cout << setw(8) << left; \
cout << #OBJ << " :"; \
void * obj_addr = get_obj_addr(OBJ); \
cout << hex << " objadr:" << obj_addr; \
void * vp_addr = get_vp_addr(obj_addr, VPOFFSET); \
cout << " vpadr:" << vp_addr; \
void * vt_addr = get_vt_addr(vp_addr); \
cout << " vtadr:" << vt_addr; \
void * vti_val = get_vti_val(vt_addr, INDEX); \
cout << " vtival(" << INDEX << "):" << vti_val << dec << right << endl; \
}

//PRINT_OBJ_ADR
#define PRINT_OBJ_ADR(OBJ) \
cout << #OBJ << "'s address is : " << hex << get_obj_addr(OBJ) << dec << endl;

//PRINT_PT
#define PRINT_PT(PT) \
cout << #PT << "'s value is : " << hex << PT << dec << endl;

struct __declspec(novtable) C180
//struct C180
{
C180() {
foo();
this->foo();
}
virtual int foo() {
cout << "<< C180.foo this: " << this << " vtadr: " << *(void**)this << endl;
}
};

struct C190 : public C180
{
C190() {}
virtual int foo() {
cout << "<< C190.foo this: " << this << " vtadr: " << *(void**)this << endl;
}
};

#pragma endregion 
int _tmain(int argc, _TCHAR* argv[])
{

	//PRINT_SIZE_DETAIL(C000);
	//PRINT_SIZE_DETAIL(C010);
	
	
	return 0;
}

