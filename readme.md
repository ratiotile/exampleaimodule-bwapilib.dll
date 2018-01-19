# Example bot using BWAPIlib as a dynamic library.
- could be necessary to share BWAPIlib between a bot and language wrapper. We want to avoid having multiple instances of Game, and having to manually update the pointers.
- BWAPI 4.2.0

## Techniques
- need to modify bwapi header files to declare dll exports/imports
- DLLEXPORT macro in dll.h
- Need to manually instantiate templates and export them using DLLEXPORT_TEMPLATE macro.
https://support.microsoft.com/en-us/help/168958/how-to-export-an-instantiation-of-a-standard-template-library-stl-clas
- BWAPILIB.dll needs to be placed in Starcraft directory in order to be found and loaded.