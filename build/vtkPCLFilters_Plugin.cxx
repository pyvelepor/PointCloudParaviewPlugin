/*=========================================================================

   Program: ParaView
   Module:    pqParaViewPlugin.cxx.in

   Copyright (c) 2005,2006 Sandia Corporation, Kitware Inc.
   All rights reserved.

   ParaView is a free software; you can redistribute it and/or modify it
   under the terms of the ParaView license version 1.2. 

   See License_v1.2.txt for the full ParaView license.
   A copy of this license can be obtained by contacting
   Kitware Inc.
   28 Corporate Drive
   Clifton Park, NY 12065
   USA

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

========================================================================*/
#include "vtkPCLFilters_Plugin.h"

#include "vtkObjectFactory.h"

#include "/home/gvis/Downloads/PointCloudLibraryPlugin-v1.0/build/vtkSMXML_vtkPCLFilters.h"

#include "/home/gvis/Downloads/PointCloudLibraryPlugin-v1.0/build/vtkPCLFilters_doc.h"

//-----------------------------------------------------------------------------
// Used to push a string returns from a function to a vector.
template <class T, class F>
void PushBack(T& vector, F& fun)
{
  char* text = fun();
  vector.push_back(text);
  delete []text;
}

//-----------------------------------------------------------------------------
#ifdef plugin_type_servermanager
# if defined(INITIALIZE_WRAPPING) || defined(INITIALIZE_EXTRA_CS_MODULES)
#  include "vtkClientServerInterpreterInitializer.h"
#  include "vtkClientServerInterpreter.h"

#   if defined(INITIALIZE_WRAPPING)
extern "C" void vtkPCLFilters_Initialize(vtkClientServerInterpreter *);
#   endif



extern "C" void VTK_EXPORT vtkPCLFilters_CombinedInitialize(
  vtkClientServerInterpreter *interp)
{
#   if defined(INITIALIZE_WRAPPING)
  vtkPCLFilters_Initialize(interp);
#   endif

  // Now initialize any extra kits as requested.
  
}
# endif
#endif

//-----------------------------------------------------------------------------
void vtkPCLFilters_Plugin::GetBinaryResources(
  std::vector<std::string>& resources)
{
  PushBack(resources, vtkPCLFilters_doc);

  (void)resources;
}

//-----------------------------------------------------------------------------
#ifdef plugin_type_gui
#define PUSH_BACK_PV_INTERFACES(arg)\
  arg.push_back(new pqPCLOpenNISourceImplementation(this));\



#include "pqPCLOpenNISourceImplementation.h"
#endif

//-----------------------------------------------------------------------------
#ifdef plugin_type_servermanager
vtkClientServerInterpreterInitializer::InterpreterInitializationCallback
vtkPCLFilters_Plugin::GetInitializeInterpreterCallback()
{
# if defined(INITIALIZE_WRAPPING) || defined(INITIALIZE_EXTRA_CS_MODULES)
  return vtkPCLFilters_CombinedInitialize;
# endif
  return NULL;
}

//-----------------------------------------------------------------------------
void vtkPCLFilters_Plugin::GetXMLs(std::vector<std::string> &xmls)
{
  PushBack(xmls, vtkPCLFiltersvtkAnnotateOBBsInterfaces);
  PushBack(xmls, vtkPCLFiltersvtkPCLEuclideanClusterExtractionInterfaces);
  PushBack(xmls, vtkPCLFiltersvtkPCLNormalEstimationInterfaces);
  PushBack(xmls, vtkPCLFiltersvtkPCLOpenNISourceInterfaces);
  PushBack(xmls, vtkPCLFiltersvtkPCLRadiusOutlierRemovalInterfaces);
  PushBack(xmls, vtkPCLFiltersvtkPCDReaderInterfaces);
  PushBack(xmls, vtkPCLFiltersvtkPCLSACSegmentationCylinderInterfaces);
  PushBack(xmls, vtkPCLFiltersvtkPCLSACSegmentationPlaneInterfaces);
  PushBack(xmls, vtkPCLFiltersvtkPCLVoxelGridInterfaces);
  PushBack(xmls, vtkPCLFiltersvtkThresholdPointsInterfaces);

  (void)xmls;
}
#endif

//-----------------------------------------------------------------------------
#ifdef plugin_type_gui
QObjectList vtkPCLFilters_Plugin::interfaces()
{
  QObjectList ifaces;
#ifdef PUSH_BACK_PV_INTERFACES
  PUSH_BACK_PV_INTERFACES(ifaces);
#endif
  return ifaces;
}
#endif

//-----------------------------------------------------------------------------
#ifdef plugin_type_python


void vtkPCLFilters_Plugin::GetPythonSourceList(std::vector<std::string>& modules,
  std::vector<std::string>& sources,
  std::vector<int> &package_flags)
{
  const char *moduleNames[] = {
    
  };
  char *moduleSources[] = {
    
  };
  const int packageFlags[] = {
    
  };

  int num_modules = sizeof(moduleNames)/sizeof(const char *);
  for (int cc=0; cc < num_modules; cc++)
    {
    modules.push_back(moduleNames[cc]);
    sources.push_back(moduleSources[cc]);
    package_flags.push_back(packageFlags[cc]);

    // free allocated memory.
    delete moduleSources[cc];
    moduleSources[cc] = NULL;
    }
}
#endif

//-----------------------------------------------------------------------------
vtkPCLFilters_Plugin::vtkPCLFilters_Plugin()
{
#ifndef BUILD_SHARED_LIBS
# ifdef plugin_type_gui
  // For static builds, initialize the Qt resources as well as the Qt plugin.
  
  Q_IMPORT_PLUGIN(vtkPCLFilters)
# endif
#endif
}

//-----------------------------------------------------------------------------
// Mark this as a ParaView-ServerManager plugin.
PV_PLUGIN_EXPORT(vtkPCLFilters, vtkPCLFilters_Plugin)

//-----------------------------------------------------------------------------
#ifdef plugin_type_gui
// Required to mark this as a Qt plugin.
Q_EXPORT_PLUGIN2(vtkPCLFilters,  vtkPCLFilters_Plugin)
#endif
