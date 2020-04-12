// Copyright 2020 Petrov Anton

#ifndef MODULES_MORTGAGE_CALCULATOR_INCLUDE_MORTGAGECALC_H_
#define MODULES_MORTGAGE_CALCULATOR_INCLUDE_MORTGAGECALC_H_

class MortgageCalc {
    int cost;
    int downPayment;
    int creditTerm;
    double interestRate;
    int totalFee;
    double monthlyPayment;
    double monthlyRate;
 public:
    MortgageCalc(int _cost, int _downPayment,
        int _creditTerm, double _interestRate);
    void calc();
    void setCost(const int& cost);
    void setDownPayment(const int& cost);
    void setCreditTerm(const int& cost);
    void setInterestRate(const double& cost);
    int getCost();
    int getDownPayment();
    int getCreditTerm();
    double getInterestRate();
    int getTotalFee();
    double getMonthlyRate();
    int getMonthlyPayment();
};

#endif  // MODULES_MORTGAGE_CALCULATOR_INCLUDE_MORTGAGECALC_H_
