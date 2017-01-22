
Rename the arch.txt to .cpp, then use the C++ wrappers to integrate a Faust generated DSP object...   
     
% faust -a arch.cpp -i -cn FaustReverb FaustReverb.dsp -o FaustReverb.h  

... and copy the FaustReverb.h to /src/faust.  


The .dsp and the arch.cpp have to be in the same directory, but it does not build as arch.cpp. You have to rename or delete it.  
