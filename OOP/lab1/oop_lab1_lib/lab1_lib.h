#ifndef _LAB1_LIB_H__INCLUDED_ 
#define _LAB1_LIB_H__INCLUDED_ 
#ifdef LAB1_LIB_BUILD_AS_SHARED_LIB 
#define LAB1_LIB_EXPORT __declspec(dllexport) 
#else 
#define LAB1_LIB_EXPORT
#endif 

// list of exported functions 
LAB1_LIB_EXPORT double GetTriangleArea_13(double sideA, double sideB, double sideC); 
#endif 

// _LAB1_LIB_H__INCLUDED_