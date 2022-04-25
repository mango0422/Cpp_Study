/*
 * 파일이름 : AccountArray.cpp
 * 작성자 : 서용준
 * 업데이트 정보 : [2020. 04.25] 파일버전 0.8
 */

 #include "BankingCommonDecl.h"
 #include "AccountArray.h"
 
 BoundCheckAccountPtrArray::BoundcheckAccountPtrArray(int len) : arrlen(len){
     arr=new ACCOUNT_PTR[len];
 }