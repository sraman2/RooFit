/*****************************************************************************
 * Project: RooFit                                                           *
 *                                                                           *
  * This code was autogenerated by RooClassFactory                            * 
 *****************************************************************************/

#ifndef POLY2SHAPE
#define POLY2SHAPE

#include "RooAbsPdf.h"
#include "RooRealProxy.h"
#include "RooCategoryProxy.h"
#include "RooAbsReal.h"
#include "RooAbsCategory.h"
 
class Poly2Shape : public RooAbsPdf {
public:
  Poly2Shape() {} ; 
  Poly2Shape(const char *name, const char *title,
	      RooAbsReal& _x,
	      RooAbsReal& _xbar,
	      RooAbsReal& _sigma);
  Poly2Shape(const Poly2Shape& other, const char* name=0) ;
  virtual TObject* clone(const char* newname) const { return new Poly2Shape(*this,newname); }
  inline virtual ~Poly2Shape() { }

  Int_t getAnalyticalIntegral(RooArgSet& allVars, RooArgSet& analVars, const char* rangeName=0) const ;
  Double_t analyticalIntegral(Int_t code, const char* rangeName=0) const ;

protected:

  RooRealProxy x ;
  RooRealProxy xbar ;
  RooRealProxy sigma ;
  
  Double_t evaluate() const ;

private:

  ClassDef(Poly2Shape,1) // second order polynomial
};
 
#endif