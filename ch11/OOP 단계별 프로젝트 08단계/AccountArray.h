/*
 * 파일이름 : AccountArray.h
 * 작성자 : 서용준
 * 업데이트 정보 : [2020. 04.25] 파일버전 0.8
 */

#ifndef __ACCOUN_ARRAY_H__
#define __ACCOUN_ARRAY_H__

#include "Account.h"
typedef Account * ACCOUNT_PTR;

class BoundCheckAccountPtrArray{
    private:
        ACCOUNT_PTR * arr;
        int arrlen;
        BoundCheckAccountPtrArray(const BoundCheckAccountPtrArray& arr){}
        BoundCheckAccountPtrArray& operator=(const BoundCheckAccountPtrArray& arr){}
    public:
        BoundCheckAccountPtrArray(int len=100);
        ACCOUNT_PTR& operator[] (int idx);
        ACCOUNT_PTR operator[] (int idx) const;
        int GetArrLen() const;
        ~BoundCheckAccountPtrArray();
};

#endif