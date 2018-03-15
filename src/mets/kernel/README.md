# kernel readme # {#knl_readme}

## knl_main
   The main of the kernel.

## scheduler
   In this module, switch kernel to userspace.
   It could schedule the terminal outside.
   All of them implemented then assembly language.

### minix
    The function restore_user_context_*.
    It define "ENTRY" for it.

### thor_os
    To use the "init_task_switch".

## knl_term

### mBuffer
    The type of "mBuffer" must be 16bit.

## dependence
   linker -> boot, knl_main -> boot.
