#include "CLASS.h"

int main(void){
    // 직원관리를 목적으로 설계된 컨트롤 클래스의 객체생성
    EmployeeHandler handler;

    // 정규직 등록
    handler.AddEmployee(new PermanentWorker("KIM", 100));
    handler.AddEmployee(new PermanentWorker("LEE", 1500));

    // 임시직 등록
    TemporaryWorker * alba=new TemporaryWorker("Jung", 700);
    alba->AddWorkTime(5);
    handler.AddEmployee(alba);

    // 영업직 등록
    SalesWorker * seller=new SalesWorker("Hong", 1000, 0.1);
    seller->AddSalesResult(7000);
    handler.AddEmployee(seller);

    // 이번 달에 지불해야 할 급여의 정보
    handler.ShowAllSalaryInfo();

    // 이번 달에 지불해야 할 급여의 총합
    handler.ShowTotalSalary();
    return (0);
}