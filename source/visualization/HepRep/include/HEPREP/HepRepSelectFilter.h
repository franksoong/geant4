// -*- C++ -*-
// AID-GENERATED
// =========================================================================
// This class was generated by AID - Abstract Interface Definition          
// DO NOT MODIFY, but use the org.freehep.aid.Aid utility to regenerate it. 
// =========================================================================
#ifndef HEPREP_HEPREPSELECTFILTER_H
#define HEPREP_HEPREPSELECTFILTER_H 1

// Copyright 2000-2002, FreeHEP.

namespace HEPREP {

class HepRepInstance;

/**
 * HepRepSelectFilter interface used in copying HepReps.
 *
 * @author Mark Donszelmann
 */
class HepRepSelectFilter {

public: 
    /// Destructor.
    virtual ~HepRepSelectFilter() { /* nop */; }

    /**
     * Selects if the given instance will pass.
     *
     * @param instance to be checked.
     * @return true if instance passes.
     */
    virtual bool select(HepRepInstance * instance) = 0;
}; // class
} // namespace HEPREP
#endif /* ifndef HEPREP_HEPREPSELECTFILTER_H */