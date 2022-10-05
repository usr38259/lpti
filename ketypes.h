
#ifndef _KETYPES_H
#define _KETYPES_H

typedef LARGE_INTEGER PHYSICAL_ADDRESS, *PPHYSICAL_ADDRESS;

typedef enum _KINTERRUPT_MODE {
  LevelSensitive,
  Latched
} KINTERRUPT_MODE;

typedef enum _INTERFACE_TYPE {
  InterfaceTypeUndefined = -1,
  Internal,
  Isa,
  Eisa,
  MicroChannel,
  TurboChannel,
  PCIBus,
  VMEBus,
  NuBus,
  PCMCIABus,
  CBus,
  MPIBus,
  MPSABus,
  ProcessorInternal,
  InternalPowerBus,
  PNPISABus,
  PNPBus,
  Vmcs,
  MaximumInterfaceType
} INTERFACE_TYPE, *PINTERFACE_TYPE;

typedef BOOLEAN
(NTAPI KSERVICE_ROUTINE)(
  IN struct _KINTERRUPT *Interrupt,
  IN PVOID ServiceContext);
typedef KSERVICE_ROUTINE *PKSERVICE_ROUTINE;

#if defined(_MSC_VER) && _MSC_VER <= 1200
typedef unsigned long ULONG_PTR, *PULONG_PTR;
typedef ULONG_PTR KAFFINITY;
typedef LONG NTSTATUS, *PNTSTATUS;
#include "winioctl.h"
#endif

#endif