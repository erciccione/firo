#ifndef ZCOIN_SIGMAPLUSPROVER_H
#define ZCOIN_SIGMAPLUSPROVER_H

#include "NextGenPrimitives.h"


namespace nextgen {

template <class Exponent, class GroupElement>
class SigmaPlusProver{

public:
    SigmaPlusProver(const GroupElement& g,
                    const std::vector<GroupElement>& h_gens, uint64_t n, uint64_t m);
    void proof(const std::vector<GroupElement>& commits,
               int l,
               const Exponent& v,
               const Exponent& r,
               SigmaPlusProof<Exponent, GroupElement>& proof_out);
    void sigma_commit(
            const std::vector<GroupElement>& commits,
            int l,
            const Exponent& rA,
            const Exponent& rB,
            const Exponent& rC,
            const Exponent& rD,
            std::vector <Exponent>& a,
            std::vector <Exponent>& Tk,
            std::vector <Exponent>& Pk,
            std::vector <Exponent>& sigma,
            SigmaPlusProof<Exponent, GroupElement>& proof_out);

    void sigma_response(
            const std::vector <Exponent>& sigma,
            const std::vector<Exponent>& a,
            const Exponent& rA,
            const Exponent& rB,
            const Exponent& rC,
            const Exponent& rD,
            const Exponent& v,
            const Exponent& r,
            const std::vector <Exponent>& Tk,
            const std::vector <Exponent>& Pk,
            const Exponent& x,
            SigmaPlusProof<Exponent, GroupElement>& proof_out);


private:
    GroupElement g_;
    zcoin_common::GeneratorVector<Exponent, GroupElement> h_;
    uint64_t n_;
    uint64_t m_;
};

}//namespace nextgen

#include "SigmaPlusProver.hpp"

#endif //ZCOIN_SIGMAPLUSPROVER_H
