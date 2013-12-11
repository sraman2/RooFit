/*****************************************************************************
 * Project: RooFit                                                           *
 *                                                                           *
 * This code was autogenerated by RooClassFactory                            * 
 *****************************************************************************/

#ifndef KEYSSHAPE
#define KEYSSHAPE

#include "StaticShape.h"

#include "TTree.h"

#include "RooDataSet.h"

#include <cstring>

class KeysShape : public StaticShape {
 public:
  KeysShape() : StaticShape() {}
  KeysShape(const char *name, const char *title, RooRealVar& _x, TTree& _ntuples, const char* _wgtVar = 0, double _rho = 0.5, unsigned _nCPU = 1, unsigned _nBins = 1000);
  KeysShape(const char *name, const char *title, RooRealVar& _x, RooDataSet& _dataset, double _rho = 0.5, unsigned _nCPU = 1, unsigned _nBins = 1000);
  KeysShape(const KeysShape& other, const char* name = 0) : StaticShape(other, name) {}
  virtual TObject* clone(const char* newname) const { return new KeysShape(*this,newname); }
  inline virtual ~KeysShape() { }

 private:
  struct CalcData {
    unsigned nData;
    double sumw;
    double h0;
    double h1;
    double const* dataval;
    double const* datawgt;
    double xmin;
    double delta;
    double rho;
    bool ownYvals;
    int nP;
    double* yvals;
    unsigned offset;
    unsigned step;

    CalcData() :
      nData(0), sumw(0.), h0(0.), h1(0.), dataval(0), datawgt(0),
      xmin(0.), delta(0.), rho(0.), ownYvals(false), nP(0), yvals(0),
      offset(0), step(0)
    {}
    CalcData(int _nP, double* _yvals = 0) :
      nData(0), sumw(0.), h0(0.), h1(0.), dataval(0), datawgt(0),
      xmin(0.), delta(0.), rho(0.), ownYvals(_yvals == 0), nP(_nP), yvals(_yvals),
      offset(0), step(0)
    {
      if(ownYvals){
        yvals = new double[nP];
        std::fill_n(yvals, nP, 0.);
      }
    }
    CalcData(CalcData const& _orig) :
      nData(_orig.nData), sumw(_orig.sumw), h0(_orig.h0), h1(_orig.h1), dataval(_orig.dataval), datawgt(_orig.datawgt),
      xmin(_orig.xmin), delta(_orig.delta), rho(_orig.rho), ownYvals(_orig.ownYvals), nP(_orig.nP), yvals(_orig.yvals),
      offset(_orig.offset), step(_orig.step)
    {
      if(ownYvals){
        yvals = new double[nP];
        std::memcpy(yvals, _orig.yvals, sizeof(double) * nP);
      }
    }
    CalcData& operator=(CalcData const& _rhs)
    {
      nData = _rhs.nData; sumw = _rhs.sumw; h0 = _rhs.h0; h1 = _rhs.h1; dataval = _rhs.dataval; datawgt = _rhs.datawgt;
      xmin = _rhs.xmin; delta = _rhs.delta; rho = _rhs.rho; ownYvals = _rhs.ownYvals;
      if(ownYvals){
        if(nP != _rhs.nP){
          nP = _rhs.nP;
          delete [] yvals;
          yvals = new double[nP];
        }
        std::memcpy(yvals, _rhs.yvals, sizeof(double) * nP);
      }
      else{
        nP = _rhs.nP;
        yvals = _rhs.yvals;
      }
      offset = _rhs.offset; step = _rhs.step;
      return *this;
    }
    ~CalcData() { if(ownYvals) delete [] yvals; }
  };

  void _calculate(unsigned, double const*, double const*, double, unsigned);

  static void* _calculateYVals(void*);

  ClassDef(KeysShape,1) // Static shape from kernel estimation of a dataset
};
 
#endif