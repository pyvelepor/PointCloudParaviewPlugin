#include "vtkClientServerInterpreter.h"

#ifndef PARAVIEW_BUILD_SHARED_LIBS
#define PARAVIEW_BUILD_SHARED_LIBS
#endif
#if defined(PARAVIEW_BUILD_SHARED_LIBS) && defined(_WIN32)
# define VTK_WRAP_CS_EXPORT __declspec(dllexport)
#else
# define VTK_WRAP_CS_EXPORT
#endif

extern void vtkAnnotateOBBs_Init(vtkClientServerInterpreter* csi);
extern void vtkPCLConversions_Init(vtkClientServerInterpreter* csi);
extern void vtkPCLEuclideanClusterExtraction_Init(vtkClientServerInterpreter* csi);
extern void vtkPCLNormalEstimation_Init(vtkClientServerInterpreter* csi);
extern void vtkPCLOpenNISource_Init(vtkClientServerInterpreter* csi);
extern void vtkPCLRadiusOutlierRemoval_Init(vtkClientServerInterpreter* csi);
extern void vtkPCDReader_Init(vtkClientServerInterpreter* csi);
extern void vtkPCLSACSegmentationCylinder_Init(vtkClientServerInterpreter* csi);
extern void vtkPCLSACSegmentationPlane_Init(vtkClientServerInterpreter* csi);
extern void vtkPCLVoxelGrid_Init(vtkClientServerInterpreter* csi);


extern "C" void VTK_WRAP_CS_EXPORT vtkPCLFilters_Initialize(
  vtkClientServerInterpreter *csi)
{
  vtkAnnotateOBBs_Init(csi);
  vtkPCLConversions_Init(csi);
  vtkPCLEuclideanClusterExtraction_Init(csi);
  vtkPCLNormalEstimation_Init(csi);
  vtkPCLOpenNISource_Init(csi);
  vtkPCLRadiusOutlierRemoval_Init(csi);
  vtkPCDReader_Init(csi);
  vtkPCLSACSegmentationCylinder_Init(csi);
  vtkPCLSACSegmentationPlane_Init(csi);
  vtkPCLVoxelGrid_Init(csi);

}
