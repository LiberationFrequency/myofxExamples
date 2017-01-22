/* ------------------------------------------------------------
name: "FaustReverb"
Code generated with Faust 2.0.a53 (http://faust.grame.fr)
------------------------------------------------------------ */

#ifndef  __FaustReverb_H__
#define  __FaustReverb_H__

// Music 256a / CS 476a | fall 2016
// CCRMA, Stanford University
//
// Author: Romain Michon (rmichonATccrmaDOTstanfordDOTedu)
// Description: Simple Faust architecture file to easily integrate a Faust DSP module
// in a JUCE project

// needed by any Faust arch file
/************************************************************************
 ************************************************************************
    FAUST Architecture File
	Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 3 of
	the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
	along with this program; If not, see <http://www.gnu.org/licenses/>.

 ************************************************************************
 ************************************************************************/
 
#ifndef __misc__
#define __misc__

#include <algorithm>
#include <map>
#include <string.h>
#include <stdlib.h>

/************************************************************************
 ************************************************************************
    FAUST Architecture File
	Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 3 of
	the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
	along with this program; If not, see <http://www.gnu.org/licenses/>.

 ************************************************************************
 ************************************************************************/
 
#ifndef __meta__
#define __meta__

struct Meta
{
    virtual void declare(const char* key, const char* value) = 0;
    virtual ~Meta() {};
};

#endif

using std::max;
using std::min;

struct XXXX_Meta : std::map<const char*, const char*>
{
    void declare(const char* key, const char* value) { (*this)[key]=value; }
};

struct MY_Meta : Meta, std::map<const char*, const char*>
{
    void declare(const char* key, const char* value) { (*this)[key]=value; }
};

inline int lsr(int x, int n)	{ return int(((unsigned int)x) >> n); }

inline int int2pow2(int x)		{ int r = 0; while ((1<<r) < x) r++; return r; }

inline long lopt(char* argv[], const char* name, long def)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return atoi(argv[i+1]);
	return def;
}

inline bool isopt(char* argv[], const char* name)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return true;
	return false;
}

inline const char* lopts(char* argv[], const char* name, const char* def)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return argv[i+1];
	return def;
}

#endif


// allows to control a Faust DSP module in a simple manner by using parameter's path
/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.


 ************************************************************************
 ************************************************************************/

#ifndef FAUST_MAPUI_H
#define FAUST_MAPUI_H

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#include <vector>
#include <map>
#include <string>

/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2016 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.


 ************************************************************************
 ************************************************************************/
 
#ifndef FAUST_UI_H
#define FAUST_UI_H

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

/*******************************************************************************
 * UI : Faust User Interface
 * This abstract class contains only the method that the faust compiler can
 * generate to describe a DSP interface.
 ******************************************************************************/

class UI
{

    public:

        UI() {}

        virtual ~UI() {}

        // -- widget's layouts

        virtual void openTabBox(const char* label) = 0;
        virtual void openHorizontalBox(const char* label) = 0;
        virtual void openVerticalBox(const char* label) = 0;
        virtual void closeBox() = 0;

        // -- active widgets

        virtual void addButton(const char* label, FAUSTFLOAT* zone) = 0;
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) = 0;
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;

        // -- passive widgets

        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) = 0;
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) = 0;

        // -- metadata declarations

        virtual void declare(FAUSTFLOAT*, const char*, const char*) {}
};

//----------------------------------------------------------------
//  Generic decorator
//----------------------------------------------------------------

class DecoratorUI : public UI
{
    protected:
    
        UI* fUI;

    public:
    
        DecoratorUI(UI* ui = 0):fUI(ui)
        {}

        virtual ~DecoratorUI() { delete fUI; }

        // -- widget's layouts
        virtual void openTabBox(const char* label)          { fUI->openTabBox(label); }
        virtual void openHorizontalBox(const char* label)   { fUI->openHorizontalBox(label); }
        virtual void openVerticalBox(const char* label)     { fUI->openVerticalBox(label); }
        virtual void closeBox()                             { fUI->closeBox(); }

        // -- active widgets
        virtual void addButton(const char* label, FAUSTFLOAT* zone)         { fUI->addButton(label, zone); }
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)    { fUI->addCheckButton(label, zone); }
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
            { fUI->addVerticalSlider(label, zone, init, min, max, step); }
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) 	
            { fUI->addHorizontalSlider(label, zone, init, min, max, step); }
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) 			
            { fUI->addNumEntry(label, zone, init, min, max, step); }

        // -- passive widgets	
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) 
            { fUI->addHorizontalBargraph(label, zone, min, max); }
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
            { fUI->addVerticalBargraph(label, zone, min, max); }

        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val) { fUI->declare(zone, key, val); }

};

#endif
/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.


 ************************************************************************
 ************************************************************************/

#ifndef FAUST_PATHBUILDER_H
#define FAUST_PATHBUILDER_H

#include <vector>
#include <string>
#include <algorithm>

/*******************************************************************************
 * PathBuilder : Faust User Interface
 * Helper class to build complete hierarchical path for UI items.
 ******************************************************************************/

class PathBuilder
{

    protected:
    
        std::vector<std::string> fControlsLevel;
       
    public:
    
        PathBuilder() {}
        virtual ~PathBuilder() {}
    
        std::string buildPath(const std::string& label) 
        {
            std::string res = "/";
            for (size_t i = 0; i < fControlsLevel.size(); i++) {
                res += fControlsLevel[i];
                res += "/";
            }
            res += label;
            replace(res.begin(), res.end(), ' ', '_');
            return res;
        }
    
};

#endif  // FAUST_PATHBUILDER_H

/*******************************************************************************
 * MapUI : Faust User Interface
 * This class creates a map of complete hierarchical path and zones for each UI items.
 ******************************************************************************/

class MapUI : public UI, public PathBuilder
{
    
    protected:
    
        // Complete path map
        std::map<std::string, FAUSTFLOAT*> fPathZoneMap;
    
        // Label zone map
        std::map<std::string, FAUSTFLOAT*> fLabelZoneMap;
    
    public:
        
        MapUI() {};
        virtual ~MapUI() {};
        
        // -- widget's layouts
        void openTabBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void openHorizontalBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void openVerticalBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void closeBox()
        {
            fControlsLevel.pop_back();
        }
        
        // -- active widgets
        void addButton(const char* label, FAUSTFLOAT* zone)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        
        // -- passive widgets
        void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        
        // -- metadata declarations
        void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {}
        
        // set/get
        void setParamValue(const std::string& path, FAUSTFLOAT value)
        {
            if (fPathZoneMap.find(path) != fPathZoneMap.end()) {
                *fPathZoneMap[path] = value;
            } else if (fLabelZoneMap.find(path) != fLabelZoneMap.end()) {
                *fLabelZoneMap[path] = value;
            }
        }
        
        FAUSTFLOAT getParamValue(const std::string& path)
        {
            if (fPathZoneMap.find(path) != fPathZoneMap.end()) {
                return *fPathZoneMap[path];
            } else if (fLabelZoneMap.find(path) != fLabelZoneMap.end()) {
                return *fLabelZoneMap[path];
            } else {
                return FAUSTFLOAT(0);
            }
        }
    
        // map access 
        std::map<std::string, FAUSTFLOAT*>& getMap() { return fPathZoneMap; }
        
        int getParamsCount() { return fPathZoneMap.size(); }
        
        std::string getParamAddress(int index)
        { 
            std::map<std::string, FAUSTFLOAT*>::iterator it = fPathZoneMap.begin();
            while (index-- > 0 && it++ != fPathZoneMap.end()) {}
            return (*it).first;
        }
};

#endif // FAUST_MAPUI_H

// needed by any Faust arch file
/************************************************************************
    IMPORTANT NOTE : this file contains two clearly delimited sections :
    the ARCHITECTURE section (in two parts) and the USER section. Each section
    is governed by its own copyright and license. Please check individually
    each section for license and copyright information.
*************************************************************************/

/*******************BEGIN ARCHITECTURE SECTION (part 1/2)****************/

/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.

 ************************************************************************
 ************************************************************************/
 
/******************************************************************************
*******************************************************************************

								FAUST DSP

*******************************************************************************
*******************************************************************************/

#ifndef __dsp__
#define __dsp__

#include <string>

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

class UI;
struct Meta;

/**
* Signal processor definition.
*/

class dsp {

    public:

        dsp() {}
        virtual ~dsp() {}

        /* Return instance number of audio inputs */
        virtual int getNumInputs() = 0;
    
        /* Return instance number of audio outputs */
        virtual int getNumOutputs() = 0;
    
        /**
         * Trigger the UI* parameter with instance specific calls
         * to 'addBtton', 'addVerticalSlider'... in order to build the UI.
         *
         * @param ui_interface - the UI* user interface builder
         */
        virtual void buildUserInterface(UI* ui_interface) = 0;
    
        /* Returns the sample rate currently used by the instance */
        virtual int getSampleRate() = 0;

        /** Global init, calls the following methods :
         * - static class 'classInit' : static table initialisation
         * - 'instanceInit' : constants and instance table initialisation
         *
         * @param samplingRate - the sampling rate in Herz
         */
        virtual void init(int samplingRate) = 0;

        /** Init instance state
         *
         * @param samplingRate - the sampling rate in Herz
         */
        virtual void instanceInit(int samplingRate) = 0;

        /** Init instance constant state
         *
         * @param samplingRate - the sampling rate in Herz
         */
        virtual void instanceConstants(int samplingRate) = 0;
    
        /* Init default control parameters values */
        virtual void instanceResetUserInterface() = 0;
    
        /* Init instance state (delay lines...) */
        virtual void instanceClear() = 0;
 
        /**
         * Return a clone of the instance.
         *
         * @return a copy of the instance on success, otherwise a null pointer.
         */
        virtual dsp* clone() = 0;
    
        /**
         * Trigger the Meta* parameter with instance specific calls to 'declare' (key, value metadata).
         *
         * @param m - the Meta* meta user
         */
        virtual void metadata(Meta* m) = 0;
    
        /**
         * DSP instance computation, to be called with sucessive in/out audio buffers.
         *
         * @param count - the nomber of frames to compute
         * @param inputs - the input audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, doucbe or quad)
         * @param outputs - the output audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, doucbe or quad)
         *
         */
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) = 0;
    
        /**
         * DSP instance computation : alternative method to be used by subclasses.
         *
         * @param date_usec - the timestamp in microsec given by audio driver.
         * @param count - the nomber of frames to compute
         * @param inputs - the input audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, doucbe or quad)
         * @param outputs - the output audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, doucbe or quad)
         *
         */
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
       
};

/**
 * Generic DSP decorator.
 */

class decorator_dsp : public dsp {

    protected:

        dsp* fDSP;

    public:

        decorator_dsp(dsp* dsp = 0):fDSP(dsp) {}
        virtual ~decorator_dsp() { delete fDSP; }

        virtual int getNumInputs() { return fDSP->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP->getNumOutputs(); }
        virtual void buildUserInterface(UI* ui_interface) { fDSP->buildUserInterface(ui_interface); }
        virtual int getSampleRate() { return fDSP->getSampleRate(); }
        virtual void init(int samplingRate) { fDSP->init(samplingRate); }
        virtual void instanceInit(int samplingRate) { fDSP->instanceInit(samplingRate); }
        virtual void instanceConstants(int samplingRate) { fDSP->instanceConstants(samplingRate); }
        virtual void instanceResetUserInterface() { fDSP->instanceResetUserInterface(); }
        virtual void instanceClear() { fDSP->instanceClear(); }
        virtual decorator_dsp* clone() { return new decorator_dsp(fDSP->clone()); }
        virtual void metadata(Meta* m) { return fDSP->metadata(m); }
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(count, inputs, outputs); }
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(date_usec, count, inputs, outputs); }
    
};

/**
 * DSP factory class
 */

class dsp_factory {
    
    protected:
    
        // So that to force sub-classes to use deleteDSPFactory(dsp_factory* factory);
        ~dsp_factory() {}
    
    public:
    
        virtual std::string getName() = 0;
        virtual std::string getSHAKey() = 0;
        virtual std::string getDSPCode() = 0;
        virtual dsp* createDSPInstance() = 0;
    
};

/**
 * On Intel set FZ (Flush to Zero) and DAZ (Denormals Are Zero)
 * flags to avoid costly denormals.
 */

#ifdef __SSE__
    #include <xmmintrin.h>
    #ifdef __SSE2__
        #define AVOIDDENORMALS _mm_setcsr(_mm_getcsr() | 0x8040)
    #else
        #define AVOIDDENORMALS _mm_setcsr(_mm_getcsr() | 0x8000)
    #endif
#else
    #define AVOIDDENORMALS
#endif

#endif

// tags used by the Faust compiler to paste the generated c++ code
#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif  

#include <math.h>


#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustReverb
#endif

class FaustReverb : public dsp {
	
 private:
	
	int iConst14;
	int iConst13;
	int iConst12;
	int iConst11;
	int iConst10;
	int iConst9;
	int iConst8;
	int iConst7;
	int iConst6;
	int iConst5;
	int iConst4;
	int iConst3;
	int IOTA;
	int fSamplingFreq;
	float fVec0[8192];
	float fVec1[8192];
	float fVec2[8192];
	float fVec3[8192];
	float fVec4[8192];
	float fVec5[8192];
	float fVec6[8192];
	float fVec7[8192];
	float fVec12[8192];
	float fVec13[8192];
	float fVec14[8192];
	float fVec15[8192];
	float fVec16[8192];
	float fVec17[8192];
	float fVec18[8192];
	float fVec19[8192];
	float fVec8[1024];
	float fVec9[1024];
	float fVec10[1024];
	float fVec11[1024];
	float fVec20[1024];
	float fVec21[1024];
	float fVec22[1024];
	float fVec23[1024];
	float fRec9[2];
	float fRec8[2];
	float fRec11[2];
	float fRec10[2];
	float fRec13[2];
	float fRec12[2];
	float fRec15[2];
	float fRec14[2];
	float fRec17[2];
	float fRec16[2];
	float fRec19[2];
	float fRec18[2];
	float fRec21[2];
	float fRec20[2];
	float fRec23[2];
	float fRec22[2];
	float fRec6[2];
	float fRec4[2];
	float fRec2[2];
	float fRec0[2];
	float fRec33[2];
	float fRec32[2];
	float fRec35[2];
	float fRec34[2];
	float fRec37[2];
	float fRec36[2];
	float fRec39[2];
	float fRec38[2];
	float fRec41[2];
	float fRec40[2];
	float fRec43[2];
	float fRec42[2];
	float fRec45[2];
	float fRec44[2];
	float fRec47[2];
	float fRec46[2];
	float fRec30[2];
	float fRec28[2];
	float fRec26[2];
	float fRec24[2];
	FAUSTFLOAT fHslider0;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider1;
	float fConst2;
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fHslider3;
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.0");
		m->declare("filters.lib/name", "Faust Filter Library");
		m->declare("filters.lib/version", "2.0");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.0");
		m->declare("name", "FaustReverb");
	}

	virtual int getNumInputs() {
		return 2;
		
	}
	virtual int getNumOutputs() {
		return 2;
		
	}
	virtual int getInputRate(int channel) {
		int rate;
		switch (channel) {
			case 0: {
				rate = 1;
				break;
			}
			case 1: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	virtual int getOutputRate(int channel) {
		int rate;
		switch (channel) {
			case 0: {
				rate = 1;
				break;
			}
			case 1: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	
	static void classInit(int samplingFreq) {
		
	}
	
	virtual void instanceConstants(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fConst0 = min(192000.0f, max(1.0f, float(fSamplingFreq)));
		fConst1 = (6.34920616e-06f * fConst0);
		fConst2 = (9.07029516e-06f * fConst0);
		iConst3 = int((0.0253061224f * fConst0));
		iConst4 = int((0.0269387756f * fConst0));
		iConst5 = int((0.0289569162f * fConst0));
		iConst6 = int((0.0307482984f * fConst0));
		iConst7 = int((0.0322448984f * fConst0));
		iConst8 = int((0.033809524f * fConst0));
		iConst9 = int((0.0353061222f * fConst0));
		iConst10 = int((0.0366666652f * fConst0));
		iConst11 = (int(((0.0126077095f * fConst0) + -1.0f)) & 1023);
		iConst12 = (int(((0.00999999978f * fConst0) + -1.0f)) & 1023);
		iConst13 = (int(((0.00773242628f * fConst0) + -1.0f)) & 1023);
		iConst14 = (int(((0.00510204071f * fConst0) + -1.0f)) & 1023);
		
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.33300000000000002f);
		fHslider1 = FAUSTFLOAT(0.5f);
		fHslider2 = FAUSTFLOAT(0.5f);
		fHslider3 = FAUSTFLOAT(0.5f);
		
	}
	
	virtual void instanceClear() {
		for (int i0 = 0; (i0 < 2); i0 = (i0 + 1)) {
			fRec9[i0] = 0.0f;
			
		}
		IOTA = 0;
		for (int i1 = 0; (i1 < 8192); i1 = (i1 + 1)) {
			fVec0[i1] = 0.0f;
			
		}
		for (int i2 = 0; (i2 < 2); i2 = (i2 + 1)) {
			fRec8[i2] = 0.0f;
			
		}
		for (int i3 = 0; (i3 < 2); i3 = (i3 + 1)) {
			fRec11[i3] = 0.0f;
			
		}
		for (int i4 = 0; (i4 < 8192); i4 = (i4 + 1)) {
			fVec1[i4] = 0.0f;
			
		}
		for (int i5 = 0; (i5 < 2); i5 = (i5 + 1)) {
			fRec10[i5] = 0.0f;
			
		}
		for (int i6 = 0; (i6 < 2); i6 = (i6 + 1)) {
			fRec13[i6] = 0.0f;
			
		}
		for (int i7 = 0; (i7 < 8192); i7 = (i7 + 1)) {
			fVec2[i7] = 0.0f;
			
		}
		for (int i8 = 0; (i8 < 2); i8 = (i8 + 1)) {
			fRec12[i8] = 0.0f;
			
		}
		for (int i9 = 0; (i9 < 2); i9 = (i9 + 1)) {
			fRec15[i9] = 0.0f;
			
		}
		for (int i10 = 0; (i10 < 8192); i10 = (i10 + 1)) {
			fVec3[i10] = 0.0f;
			
		}
		for (int i11 = 0; (i11 < 2); i11 = (i11 + 1)) {
			fRec14[i11] = 0.0f;
			
		}
		for (int i12 = 0; (i12 < 2); i12 = (i12 + 1)) {
			fRec17[i12] = 0.0f;
			
		}
		for (int i13 = 0; (i13 < 8192); i13 = (i13 + 1)) {
			fVec4[i13] = 0.0f;
			
		}
		for (int i14 = 0; (i14 < 2); i14 = (i14 + 1)) {
			fRec16[i14] = 0.0f;
			
		}
		for (int i15 = 0; (i15 < 2); i15 = (i15 + 1)) {
			fRec19[i15] = 0.0f;
			
		}
		for (int i16 = 0; (i16 < 8192); i16 = (i16 + 1)) {
			fVec5[i16] = 0.0f;
			
		}
		for (int i17 = 0; (i17 < 2); i17 = (i17 + 1)) {
			fRec18[i17] = 0.0f;
			
		}
		for (int i18 = 0; (i18 < 2); i18 = (i18 + 1)) {
			fRec21[i18] = 0.0f;
			
		}
		for (int i19 = 0; (i19 < 8192); i19 = (i19 + 1)) {
			fVec6[i19] = 0.0f;
			
		}
		for (int i20 = 0; (i20 < 2); i20 = (i20 + 1)) {
			fRec20[i20] = 0.0f;
			
		}
		for (int i21 = 0; (i21 < 2); i21 = (i21 + 1)) {
			fRec23[i21] = 0.0f;
			
		}
		for (int i22 = 0; (i22 < 8192); i22 = (i22 + 1)) {
			fVec7[i22] = 0.0f;
			
		}
		for (int i23 = 0; (i23 < 2); i23 = (i23 + 1)) {
			fRec22[i23] = 0.0f;
			
		}
		for (int i24 = 0; (i24 < 1024); i24 = (i24 + 1)) {
			fVec8[i24] = 0.0f;
			
		}
		for (int i25 = 0; (i25 < 2); i25 = (i25 + 1)) {
			fRec6[i25] = 0.0f;
			
		}
		for (int i26 = 0; (i26 < 1024); i26 = (i26 + 1)) {
			fVec9[i26] = 0.0f;
			
		}
		for (int i27 = 0; (i27 < 2); i27 = (i27 + 1)) {
			fRec4[i27] = 0.0f;
			
		}
		for (int i28 = 0; (i28 < 1024); i28 = (i28 + 1)) {
			fVec10[i28] = 0.0f;
			
		}
		for (int i29 = 0; (i29 < 2); i29 = (i29 + 1)) {
			fRec2[i29] = 0.0f;
			
		}
		for (int i30 = 0; (i30 < 1024); i30 = (i30 + 1)) {
			fVec11[i30] = 0.0f;
			
		}
		for (int i31 = 0; (i31 < 2); i31 = (i31 + 1)) {
			fRec0[i31] = 0.0f;
			
		}
		for (int i32 = 0; (i32 < 2); i32 = (i32 + 1)) {
			fRec33[i32] = 0.0f;
			
		}
		for (int i33 = 0; (i33 < 8192); i33 = (i33 + 1)) {
			fVec12[i33] = 0.0f;
			
		}
		for (int i34 = 0; (i34 < 2); i34 = (i34 + 1)) {
			fRec32[i34] = 0.0f;
			
		}
		for (int i35 = 0; (i35 < 2); i35 = (i35 + 1)) {
			fRec35[i35] = 0.0f;
			
		}
		for (int i36 = 0; (i36 < 8192); i36 = (i36 + 1)) {
			fVec13[i36] = 0.0f;
			
		}
		for (int i37 = 0; (i37 < 2); i37 = (i37 + 1)) {
			fRec34[i37] = 0.0f;
			
		}
		for (int i38 = 0; (i38 < 2); i38 = (i38 + 1)) {
			fRec37[i38] = 0.0f;
			
		}
		for (int i39 = 0; (i39 < 8192); i39 = (i39 + 1)) {
			fVec14[i39] = 0.0f;
			
		}
		for (int i40 = 0; (i40 < 2); i40 = (i40 + 1)) {
			fRec36[i40] = 0.0f;
			
		}
		for (int i41 = 0; (i41 < 2); i41 = (i41 + 1)) {
			fRec39[i41] = 0.0f;
			
		}
		for (int i42 = 0; (i42 < 8192); i42 = (i42 + 1)) {
			fVec15[i42] = 0.0f;
			
		}
		for (int i43 = 0; (i43 < 2); i43 = (i43 + 1)) {
			fRec38[i43] = 0.0f;
			
		}
		for (int i44 = 0; (i44 < 2); i44 = (i44 + 1)) {
			fRec41[i44] = 0.0f;
			
		}
		for (int i45 = 0; (i45 < 8192); i45 = (i45 + 1)) {
			fVec16[i45] = 0.0f;
			
		}
		for (int i46 = 0; (i46 < 2); i46 = (i46 + 1)) {
			fRec40[i46] = 0.0f;
			
		}
		for (int i47 = 0; (i47 < 2); i47 = (i47 + 1)) {
			fRec43[i47] = 0.0f;
			
		}
		for (int i48 = 0; (i48 < 8192); i48 = (i48 + 1)) {
			fVec17[i48] = 0.0f;
			
		}
		for (int i49 = 0; (i49 < 2); i49 = (i49 + 1)) {
			fRec42[i49] = 0.0f;
			
		}
		for (int i50 = 0; (i50 < 2); i50 = (i50 + 1)) {
			fRec45[i50] = 0.0f;
			
		}
		for (int i51 = 0; (i51 < 8192); i51 = (i51 + 1)) {
			fVec18[i51] = 0.0f;
			
		}
		for (int i52 = 0; (i52 < 2); i52 = (i52 + 1)) {
			fRec44[i52] = 0.0f;
			
		}
		for (int i53 = 0; (i53 < 2); i53 = (i53 + 1)) {
			fRec47[i53] = 0.0f;
			
		}
		for (int i54 = 0; (i54 < 8192); i54 = (i54 + 1)) {
			fVec19[i54] = 0.0f;
			
		}
		for (int i55 = 0; (i55 < 2); i55 = (i55 + 1)) {
			fRec46[i55] = 0.0f;
			
		}
		for (int i56 = 0; (i56 < 1024); i56 = (i56 + 1)) {
			fVec20[i56] = 0.0f;
			
		}
		for (int i57 = 0; (i57 < 2); i57 = (i57 + 1)) {
			fRec30[i57] = 0.0f;
			
		}
		for (int i58 = 0; (i58 < 1024); i58 = (i58 + 1)) {
			fVec21[i58] = 0.0f;
			
		}
		for (int i59 = 0; (i59 < 2); i59 = (i59 + 1)) {
			fRec28[i59] = 0.0f;
			
		}
		for (int i60 = 0; (i60 < 1024); i60 = (i60 + 1)) {
			fVec22[i60] = 0.0f;
			
		}
		for (int i61 = 0; (i61 < 2); i61 = (i61 + 1)) {
			fRec26[i61] = 0.0f;
			
		}
		for (int i62 = 0; (i62 < 1024); i62 = (i62 + 1)) {
			fVec23[i62] = 0.0f;
			
		}
		for (int i63 = 0; (i63 < 2); i63 = (i63 + 1)) {
			fRec24[i63] = 0.0f;
			
		}
		
	}
	
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void instanceInit(int samplingFreq) {
		instanceConstants(samplingFreq);
		instanceResetUserInterface();
		instanceClear();
	}
	
	virtual FaustReverb* clone() {
		return new FaustReverb();
	}
	
	virtual int getSampleRate() {
		return fSamplingFreq;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("0x00");
		ui_interface->addHorizontalSlider("Damping", &fHslider2, 0.5f, 0.0f, 1.0f, 0.0250000004f);
		ui_interface->addHorizontalSlider("Dry/Wet", &fHslider0, 0.333000004f, 0.0f, 1.0f, 0.00999999978f);
		ui_interface->addHorizontalSlider("Room Size", &fHslider1, 0.5f, 0.0f, 1.0f, 0.0250000004f);
		ui_interface->addHorizontalSlider("Stereo Spread", &fHslider3, 0.5f, 0.0f, 1.0f, 0.00999999978f);
		ui_interface->closeBox();
		
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = float(fHslider0);
		float fSlow1 = (0.100000001f * fSlow0);
		float fSlow2 = ((fConst1 * float(fHslider1)) + 0.699999988f);
		float fSlow3 = (fConst2 * float(fHslider2));
		float fSlow4 = (1.0f - fSlow3);
		float fSlow5 = (1.0f - fSlow0);
		float fSlow6 = (0.00104308384f * float(fHslider3));
		int iSlow7 = int((fConst0 * (fSlow6 + 0.0253061224f)));
		int iSlow8 = int((fConst0 * (fSlow6 + 0.0269387756f)));
		int iSlow9 = int((fConst0 * (fSlow6 + 0.0289569162f)));
		int iSlow10 = int((fConst0 * (fSlow6 + 0.0307482984f)));
		int iSlow11 = int((fConst0 * (fSlow6 + 0.0322448984f)));
		int iSlow12 = int((fConst0 * (fSlow6 + 0.033809524f)));
		int iSlow13 = int((fConst0 * (fSlow6 + 0.0353061222f)));
		int iSlow14 = int((fConst0 * (fSlow6 + 0.0366666652f)));
		int iSlow15 = (int(((fConst0 * (fSlow6 + 0.0126077095f)) + -1.0f)) & 1023);
		int iSlow16 = (int(((fConst0 * (fSlow6 + 0.00999999978f)) + -1.0f)) & 1023);
		int iSlow17 = (int(((fConst0 * (fSlow6 + 0.00773242628f)) + -1.0f)) & 1023);
		int iSlow18 = (int(((fConst0 * (fSlow6 + 0.00510204071f)) + -1.0f)) & 1023);
		for (int i = 0; (i < count); i = (i + 1)) {
			float fTemp0 = float(input0[i]);
			float fTemp1 = float(input1[i]);
			float fTemp2 = (fSlow1 * (fTemp0 + fTemp1));
			fRec9[0] = ((fSlow4 * fRec8[1]) + (fSlow3 * fRec9[1]));
			fVec0[(IOTA & 8191)] = (fTemp2 + (fSlow2 * fRec9[0]));
			fRec8[0] = fVec0[((IOTA - iConst3) & 8191)];
			fRec11[0] = ((fSlow4 * fRec10[1]) + (fSlow3 * fRec11[1]));
			fVec1[(IOTA & 8191)] = (fTemp2 + (fSlow2 * fRec11[0]));
			fRec10[0] = fVec1[((IOTA - iConst4) & 8191)];
			fRec13[0] = ((fSlow4 * fRec12[1]) + (fSlow3 * fRec13[1]));
			fVec2[(IOTA & 8191)] = (fTemp2 + (fSlow2 * fRec13[0]));
			fRec12[0] = fVec2[((IOTA - iConst5) & 8191)];
			fRec15[0] = ((fSlow4 * fRec14[1]) + (fSlow3 * fRec15[1]));
			fVec3[(IOTA & 8191)] = (fTemp2 + (fSlow2 * fRec15[0]));
			fRec14[0] = fVec3[((IOTA - iConst6) & 8191)];
			fRec17[0] = ((fSlow4 * fRec16[1]) + (fSlow3 * fRec17[1]));
			fVec4[(IOTA & 8191)] = (fTemp2 + (fSlow2 * fRec17[0]));
			fRec16[0] = fVec4[((IOTA - iConst7) & 8191)];
			fRec19[0] = ((fSlow4 * fRec18[1]) + (fSlow3 * fRec19[1]));
			fVec5[(IOTA & 8191)] = (fTemp2 + (fSlow2 * fRec19[0]));
			fRec18[0] = fVec5[((IOTA - iConst8) & 8191)];
			fRec21[0] = ((fSlow4 * fRec20[1]) + (fSlow3 * fRec21[1]));
			fVec6[(IOTA & 8191)] = (fTemp2 + (fSlow2 * fRec21[0]));
			fRec20[0] = fVec6[((IOTA - iConst9) & 8191)];
			fRec23[0] = ((fSlow4 * fRec22[1]) + (fSlow3 * fRec23[1]));
			fVec7[(IOTA & 8191)] = (fTemp2 + (fSlow2 * fRec23[0]));
			fRec22[0] = fVec7[((IOTA - iConst10) & 8191)];
			float fTemp3 = ((((((((fRec8[0] + fRec10[0]) + fRec12[0]) + fRec14[0]) + fRec16[0]) + fRec18[0]) + fRec20[0]) + fRec22[0]) - (0.5f * fRec6[1]));
			fVec8[(IOTA & 1023)] = fTemp3;
			fRec6[0] = fVec8[((IOTA - iConst11) & 1023)];
			float fRec7 = (0.5f * fTemp3);
			float fTemp4 = ((fRec6[1] + fRec7) - (0.5f * fRec4[1]));
			fVec9[(IOTA & 1023)] = fTemp4;
			fRec4[0] = fVec9[((IOTA - iConst12) & 1023)];
			float fRec5 = (0.5f * fTemp4);
			float fTemp5 = ((fRec4[1] + fRec5) - (0.5f * fRec2[1]));
			fVec10[(IOTA & 1023)] = fTemp5;
			fRec2[0] = fVec10[((IOTA - iConst13) & 1023)];
			float fRec3 = (0.5f * fTemp5);
			float fTemp6 = ((fRec2[1] + fRec3) - (0.5f * fRec0[1]));
			fVec11[(IOTA & 1023)] = fTemp6;
			fRec0[0] = fVec11[((IOTA - iConst14) & 1023)];
			float fRec1 = (0.5f * fTemp6);
			output0[i] = FAUSTFLOAT((fRec1 + ((fSlow5 * fTemp0) + fRec0[1])));
			fRec33[0] = ((fSlow4 * fRec32[1]) + (fSlow3 * fRec33[1]));
			fVec12[(IOTA & 8191)] = (fTemp2 + (fSlow2 * fRec33[0]));
			fRec32[0] = fVec12[((IOTA - iSlow7) & 8191)];
			fRec35[0] = ((fSlow4 * fRec34[1]) + (fSlow3 * fRec35[1]));
			fVec13[(IOTA & 8191)] = (fTemp2 + (fSlow2 * fRec35[0]));
			fRec34[0] = fVec13[((IOTA - iSlow8) & 8191)];
			fRec37[0] = ((fSlow4 * fRec36[1]) + (fSlow3 * fRec37[1]));
			fVec14[(IOTA & 8191)] = (fTemp2 + (fSlow2 * fRec37[0]));
			fRec36[0] = fVec14[((IOTA - iSlow9) & 8191)];
			fRec39[0] = ((fSlow4 * fRec38[1]) + (fSlow3 * fRec39[1]));
			fVec15[(IOTA & 8191)] = (fTemp2 + (fSlow2 * fRec39[0]));
			fRec38[0] = fVec15[((IOTA - iSlow10) & 8191)];
			fRec41[0] = ((fSlow4 * fRec40[1]) + (fSlow3 * fRec41[1]));
			fVec16[(IOTA & 8191)] = (fTemp2 + (fSlow2 * fRec41[0]));
			fRec40[0] = fVec16[((IOTA - iSlow11) & 8191)];
			fRec43[0] = ((fSlow4 * fRec42[1]) + (fSlow3 * fRec43[1]));
			fVec17[(IOTA & 8191)] = (fTemp2 + (fSlow2 * fRec43[0]));
			fRec42[0] = fVec17[((IOTA - iSlow12) & 8191)];
			fRec45[0] = ((fSlow4 * fRec44[1]) + (fSlow3 * fRec45[1]));
			fVec18[(IOTA & 8191)] = (fTemp2 + (fSlow2 * fRec45[0]));
			fRec44[0] = fVec18[((IOTA - iSlow13) & 8191)];
			fRec47[0] = ((fSlow4 * fRec46[1]) + (fSlow3 * fRec47[1]));
			fVec19[(IOTA & 8191)] = (fTemp2 + (fSlow2 * fRec47[0]));
			fRec46[0] = fVec19[((IOTA - iSlow14) & 8191)];
			float fTemp7 = ((((((((fRec32[0] + fRec34[0]) + fRec36[0]) + fRec38[0]) + fRec40[0]) + fRec42[0]) + fRec44[0]) + fRec46[0]) - (0.5f * fRec30[1]));
			fVec20[(IOTA & 1023)] = fTemp7;
			fRec30[0] = fVec20[((IOTA - iSlow15) & 1023)];
			float fRec31 = (0.5f * fTemp7);
			float fTemp8 = ((fRec30[1] + fRec31) - (0.5f * fRec28[1]));
			fVec21[(IOTA & 1023)] = fTemp8;
			fRec28[0] = fVec21[((IOTA - iSlow16) & 1023)];
			float fRec29 = (0.5f * fTemp8);
			float fTemp9 = ((fRec28[1] + fRec29) - (0.5f * fRec26[1]));
			fVec22[(IOTA & 1023)] = fTemp9;
			fRec26[0] = fVec22[((IOTA - iSlow17) & 1023)];
			float fRec27 = (0.5f * fTemp9);
			float fTemp10 = ((fRec26[1] + fRec27) - (0.5f * fRec24[1]));
			fVec23[(IOTA & 1023)] = fTemp10;
			fRec24[0] = fVec23[((IOTA - iSlow18) & 1023)];
			float fRec25 = (0.5f * fTemp10);
			output1[i] = FAUSTFLOAT((fRec25 + ((fSlow5 * fTemp1) + fRec24[1])));
			fRec9[1] = fRec9[0];
			IOTA = (IOTA + 1);
			fRec8[1] = fRec8[0];
			fRec11[1] = fRec11[0];
			fRec10[1] = fRec10[0];
			fRec13[1] = fRec13[0];
			fRec12[1] = fRec12[0];
			fRec15[1] = fRec15[0];
			fRec14[1] = fRec14[0];
			fRec17[1] = fRec17[0];
			fRec16[1] = fRec16[0];
			fRec19[1] = fRec19[0];
			fRec18[1] = fRec18[0];
			fRec21[1] = fRec21[0];
			fRec20[1] = fRec20[0];
			fRec23[1] = fRec23[0];
			fRec22[1] = fRec22[0];
			fRec6[1] = fRec6[0];
			fRec4[1] = fRec4[0];
			fRec2[1] = fRec2[0];
			fRec0[1] = fRec0[0];
			fRec33[1] = fRec33[0];
			fRec32[1] = fRec32[0];
			fRec35[1] = fRec35[0];
			fRec34[1] = fRec34[0];
			fRec37[1] = fRec37[0];
			fRec36[1] = fRec36[0];
			fRec39[1] = fRec39[0];
			fRec38[1] = fRec38[0];
			fRec41[1] = fRec41[0];
			fRec40[1] = fRec40[0];
			fRec43[1] = fRec43[0];
			fRec42[1] = fRec42[0];
			fRec45[1] = fRec45[0];
			fRec44[1] = fRec44[0];
			fRec47[1] = fRec47[0];
			fRec46[1] = fRec46[0];
			fRec30[1] = fRec30[0];
			fRec28[1] = fRec28[0];
			fRec26[1] = fRec26[0];
			fRec24[1] = fRec24[0];
			
		}
		
	}

	
};


#endif
