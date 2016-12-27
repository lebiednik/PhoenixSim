//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

#include "StatObject_HURST.h"

StatObject_HURST::StatObject_HURST(string n) :
	StatObject(n) {
	type = HURST;

	total = 0;
	count = 0;
}

StatObject_HURST::~StatObject_HURST() {
	// TODO Auto-generated destructor stub
}

void StatObject_HURST::stat_track(double d) {

	total += d;
	count++;

	points.push_back(d);
}

string StatObject_HURST::getHeader() {
	return "Mean,StdDev";
}

void StatObject_HURST::writeValue(ofstream *of) {

    double mH = 0;
    double sH = 0;
    int maxT = 19;
    double* auxH;
    int Tmax;
    int k = 0;
    int L;
    int* x;
    int* XX;
    double* mcord;
    double* dV;
    double* VV;
    int tt = 0;
    double N = 0;
    long int NN = 0;
    double mx = 0; double my = 0;
    unsigned long long int SSxx = 0; double SSxy = 0;
    double SSxx2 = 0; double SSxy2 = 0;
    double cc1 = 0; double cc2 = 0;
    double meanabsddVd = 0;
    double meanabsVVVd = 0;


    // S ====> points
    // L ====> count
    L = count;
    auxH = (double*) malloc((maxT-4)*sizeof(double));

    dV = (double*) malloc((L-1)*sizeof(double));
    VV = (double*) malloc(L*sizeof(double));
    x = (int*) malloc(maxT*sizeof(int));
    mcord = (double*) malloc(maxT*sizeof(double));
    XX = (int*) malloc(L*sizeof(int));


    //list<double>::iterator iter1;
    //for(iter1 = points.begin(); iter1 != points.end(); iter1++){
    //    (*of) << *iter1 << ",";
    //}

    for(Tmax=5;Tmax<maxT+1;Tmax++)
    {
        k++;

        for(int i=1;i<Tmax+1;i++) {
            x[i-1] = i;
            mcord[i-1] = 0;
        }

        for(tt=1;tt<Tmax+1;tt++)
        {

            list<double>::iterator iter;
            long int j=0; long int l=0;
            for(iter = points.begin(); iter != points.end(); iter++){

                if(j%tt==0){
                    VV[l] = *iter;
                    l++;
                }
                j++;
            }

            for(long int i=0;i<l-1;i++) {
                dV[i] = VV[i+1]-VV[i];
            }


            N = ceil((double)L/tt);
            NN = (long int) N;
            mx = 0; SSxx = 0;
            my = 0; SSxy = 0;
            for(long int i=1;i<NN+1;i++) {
                XX[i-1] = i;
                mx += i;
                unsigned long long int ii = 0;
                ii = (unsigned long long int)i*i;
                SSxx = SSxx + ii;
                my += VV[i-1];
                SSxy = SSxy + XX[i-1]*VV[i-1];
            }
            // Y = VV
            mx = mx/NN; my = my/NN;
            SSxx = SSxx - (unsigned long long int) NN*mx*mx;
            SSxy = SSxy - NN*mx*my;
            cc1 = SSxy/SSxx;
            cc2 = my - cc1*mx;

            //mcord[tt-1] = mean(abs(ddVd)) / mean(abs(VVVd));
            //ddVd[i] = dV[i] - cc1;
            //VVVd[i-1] = VV[i-1] - cc1*i - cc2;
            meanabsddVd = 0;
            meanabsVVVd = 0;

            for(long int i=0;i<NN-1;i++) {
                meanabsddVd += fabs(dV[i] - cc1);
            }
            meanabsddVd = meanabsddVd / (NN-1);

            for(long int i=0;i<NN;i++) {
                meanabsVVVd += fabs(VV[i] - cc1*(i+1) - cc2);
            }
            meanabsVVVd = meanabsVVVd / NN;

            mcord[tt-1] = meanabsddVd / meanabsVVVd;


        }

        mx = 0; my = 0;
        SSxx2 = 0; SSxy2 = 0;
        for(int i=0;i<Tmax;i++){
            mx += log10(x[i]);
            SSxx2 += log10(x[i])*log10(x[i]);
            my += log10(mcord[i]);
            SSxy2 += log10(x[i])*log10(mcord[i]);
        }
        mx = mx/Tmax; my = my/Tmax;
        SSxx2 = SSxx2 - Tmax*mx*mx;
        SSxy2 = SSxy2 - Tmax*mx*my;
        auxH[k-1] = SSxy2 / SSxx2;

    }

    free(dV); free(VV); free(XX); free(mcord); free(x);
    mH = 0; sH = 0;
    for(int i=0;i<maxT-4;i++) {
        mH += auxH[i];
    }
    mH = mH/(maxT-4);

    for(int i=0;i<maxT-4;i++) {
        sH += pow((mH - auxH[i]),2);
    }
    sH = sH / (maxT-4);
    sH = sqrt(sH);


	(*of) << mH << "," << sH;
}
