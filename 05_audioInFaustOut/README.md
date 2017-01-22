An slightly modified example from a lecture at the Stanford University's Center for Computer Research in Music and Acoustics (CCRMA) how using Faust in OpenFrameworks.         
https://ccrma.stanford.edu/courses/256a-fall-2016/  
https://ccrma.stanford.edu/courses/256a-fall-2016/codes/ofxFaustExample.zip  

Unfortunately the associated Faust code was not available, so I used a FreeVerb from a previous workshop and followed the procedure [Making C++ DSP Modules with Faust] above - see /src/dsp   
https://ccrma.stanford.edu/~rmichon/faustWorkshops/2016/#freeverb   

It is just the OpenFrameworks audioInputExample with the added Faust FreeVerb and routed to the output.  



-------------------------------------------------------------------------------------------
# `faustExample` : Using Faust in OpenFrameworks

This project is just the OpenFrameworks **`audioOutputExample`** (see `OpenFrameworks/examples/sound/audioOutputExample`), but with add reverb via Faust! This is very similar to the way we added Faust reverb to the FM project in JUCE (recall the [FMReverb starter code](https://ccrma.stanford.edu/courses/256a-fall-2016/codes/FMReverb.zip)), but we're doing it in [OpenFrameworks](http://openframeworks.cc/) now.

## To build

* Extract this directory and place it in your `$OF/apps/myapps/` directory, where `$OF` is the path to your OpenFrameworks directory. For example, this would end up in `/Users/tim/Desktop/of_v0.9.5_osx_release/apps/myApps/ofxFaustExample/` on my OSX machine.

* Build the program.
    * On OSX, open up `faustExample.xcodeproj` and build the target for "*faustExample Release > My Mac (64 bit)*" (or Debug, or 32-bit, etc.)
    * On Linux, you can type `make` from the project directory. Alternately, if you want to use the [QtCreator IDE](https://www.qt.io/ide/), you can open up `faustExample.creator` and build.
    * Windows is untested, but you should be able to import the project into Visual Studio or QtCreator after you've followed the general OpenFrameworks installation directions.

* The compiled program should now be in your `faustExample/bin` directory.

## Further reading

As you can see in this project's `./src/ofApp.h` and `./src/ofApp.cpp` files, we are following the procedure in Romain's [Making C++ DSP Modules with Faust](https://ccrma.stanford.edu/courses/256a-fall-2016/lectures/faust/) lecture.





  