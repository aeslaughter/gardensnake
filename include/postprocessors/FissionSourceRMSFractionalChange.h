/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#ifndef FISSIONSOURCERMSFRACTIONALCHANGE_H
#define FISSIONSOURCERMSFRACTIONALCHANGE_H

#include "ZoneElementAverageValue.h"

//Forward Declarations
class FissionSourceRMSFractionalChange;

template<>
InputParameters validParams<FissionSourceRMSFractionalChange>();

class FissionSourceRMSFractionalChange : public ZoneElementAverageValue
{
public:
  FissionSourceRMSFractionalChange(const std::string & name, InputParameters parameters);
  virtual Real getValue();

protected:
  virtual Real computeQpIntegral();

  MaterialProperty<std::vector<Real> > & _nu_sigma_f;

  // The values of all of the fluxes
  std::vector<VariableValue *> _fluxes;
  std::vector<VariableValue *> _fluxes_old;
};

#endif
