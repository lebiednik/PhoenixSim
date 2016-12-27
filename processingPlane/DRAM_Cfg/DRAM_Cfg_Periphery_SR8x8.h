/*
 * DRAM_Cfg_Periphery.h
 *
 *  Created on: Feb 18, 2009
 *      Author: Gilbert
 */

#ifndef DRAM_CFG_PERIPHERY_SR8x8_H_
#define DRAM_CFG_PERIPHERY_SR8x8_H_

#include "DRAM_Cfg.h"

class DRAM_Cfg_Periphery_SR8x8 : public DRAM_Cfg {
public:
	DRAM_Cfg_Periphery_SR8x8(int n, int pC);
	virtual ~DRAM_Cfg_Periphery_SR8x8();

	virtual int getNumDRAM();

protected:

	virtual int get_bank_id(int coreId, int x, int y);
	virtual int get_access_node(int dramId);

	map<int, int> bMap;
	map<int, int> aMap;

};

#endif /* DRAM_CFG_PERIPHERY_H_ */


