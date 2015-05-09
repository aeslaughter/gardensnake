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

#ifndef XSMATERIAL_H
#define XSMATERIAL_H

#include "Material.h"


//Forward Declarations
class XSMaterial;

template<>
InputParameters validParams<XSMaterial>();

class XSMaterial : public Material
{
public:
  XSMaterial(const std::string & name, InputParameters parameters);

protected:
  virtual void computeQpProperties();

  VariableValue & _current_zone;

  class Zone
  {
  public:
    /// Indexed by group!
    std::vector<Real> diffusivity;
    std::vector<Real> sigma_a;
    std::vector<std::vector<Real> > sigma_s;
    std::vector<Real> nu_sigma_f;
  };

  std::vector<Zone> _zones;

  /// Diffusivity coefficient for each group
  MaterialProperty<std::vector<Real> > & _diffusivity;

  /// Absorption XS for each group
  MaterialProperty<std::vector<Real> > & _sigma_a;

  /// Scattering cross section (full matrix: column->row)
  MaterialProperty<std::vector<std::vector<Real> > > & _sigma_s;

  /// Fission XS for each group
  MaterialProperty<std::vector<Real> > & _nu_sigma_f;

  /// Edges of each zone
  const std::vector<Real> & _zone_edges;

  /// Each zone that goes with the zone_edges
  const std::vector<Real> & _zone_numbers;
};

#endif //XSMATERIAL_H
