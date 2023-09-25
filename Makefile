RIOTEE_SDK_ROOT ?=
GNU_INSTALL_ROOT ?=

PRJ_ROOT := .
OUTPUT_DIR := _build

# Size of the user stack in bytes. Must be multiple of 4.
RIOTEE_STACK_SIZE:= 1024
# Size of retained memory in bytes including STACK_SIZE.
RIOTEE_RAM_RETAINED_SIZE:= 8192


ifndef RIOTEE_SDK_ROOT
  $(error RIOTEE_SDK_ROOT is not set)
endif

SRC_FILES = \
  $(PRJ_ROOT)/src/main.c

INC_DIRS = \
  $(PRJ_ROOT)/include

include $(RIOTEE_SDK_ROOT)/Makefile
