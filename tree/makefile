#----------- debug mode -------------------------------------------------------------------
USE_DEBUG ?= false
#------------------------------------------------------------------------------------------


#---------- archive libs ------------------------------------------------------------------
ARCHIVES_NAMES =
ARCHIVES_DIRS  =
#------------------------------------------------------------------------------------------


#------------ dirs ------------------------------------------------------------------------
TREE_SRC_DIR   	= src
TREE_BUILD_DIR 	= build
TREE_OBJ_DIR   	= $(TREE_BUILD_DIR)/obj
TREE_DEP_DIR   	= $(TREE_BUILD_DIR)/.deps

LOGS_DIR	  	?= popa_log
GRAPH_DIR	  	?= popa_graph

RELEASE_DIRS_MK = TREE_SRC_DIR TREE_BUILD_DIR TREE_OBJ_DIR TREE_DEP_DIR
DEBUG_DIRS_MK	=
#------------------------------------------------------------------------------------------


#----------- define variables -------------------------------------------------------------
BUILD_FOLDER_NAME = \"$(TREE_BUILD_DIR)\"

LOGS_FOLDER_NAME  = \"$(LOGS_DIR)\"
GRAPH_FOLDER_NAME = \"$(GRAPH_DIR)\"

DEFINE_VARS = BUILD_FOLDER_NAME LOGS_FOLDER_NAME GRAPH_FOLDER_NAME
#------------------------------------------------------------------------------------------


ARCHIVES_DEBUG_FLAGS = $(foreach project,$(ARCHIVES_NAMES),-D $(shell echo $(project) | tr '[:lower:]' '[:upper:]')_DEBUG)
ARCHIVE_NAMES_FLAGS  = $(addprefix -l,   $(ARCHIVES_NAMES))
ARCHIVES_DIRS_FLAGS  = $(foreach arch_dir, $(ARCHIVES_DIRS), -L$(arch_dir)/$(FRONTEND_OBJ_DIR))
ARCHIVES_DIRS_LIBS   = $(addsuffix /lib, $(ARCHIVES_DIRS))

DEFINE_VARS_FLAGS 	 = $(foreach var,$(DEFINE_VARS),-D $(var)=$($(var)))

DEBUG_FLAGS   = -D TREE_DEBUG -D _DEBUG  -ggdb -Og -g3 -D_FORTIFY_SOURCES=3 $(SANITIZER) $(ARCHIVES_DEBUG_FLAGS)
RELEASE_FLAGS = -DNDEBUG -O3

INCLUDES      = lib $(ARCHIVES_DIRS_LIBS)
INCLUDE_FLAGS = $(addprefix -I ,$(INCLUDES))


TREE_CPP	  = $(wildcard $(TREE_SRC_DIR)/*.cpp)
TREE_OBJ      = $(patsubst $(TREE_SRC_DIR)/%.cpp,$(TREE_OBJ_DIR)/%.o,$(TREE_CPP))
TREE_DEP      = $(patsubst $(TREE_SRC_DIR)/%.cpp,$(TREE_DEP_DIR)/%.d,$(TREE_CPP))

DEPFLAGS = -MT $@ -MMD -MP -MF $(TREE_DEP_DIR)/$*.d

TARGET_ARCHIVE = $(TREE_OBJ_DIR)/libtree.a 

FLAGS  = -Wall -Wextra -Weffc++ -Waggressive-loop-optimizations -Wc++14-compat -Wmissing-declarations -Wcast-align -Wcast-qual                									\
 -Wchar-subscripts -Wconditionally-supported -Wconversion -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness               \
 -Wformat=2 -Winline -Wlogical-op -Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion         \
 -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=2 -Wsuggest-attribute=noreturn -Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override -Wswitch-default            \
 -Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wuseless-cast -Wvariadic-macros -Wno-literal-suffix -Wno-missing-field-initializers -Wno-narrowing                  \
 -Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation -fstack-protector -fstrict-overflow -flto-odr-type-merging -fno-omit-frame-pointer              \
 -Wlarger-than=81920 -Wstack-usage=81920 -no-pie -Werror=vla

SANITIZER = -fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,leak,nonnull-attribute,null,object-size,$\
			return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr

ifeq ($(USE_DEBUG), true)
	FLAGS += $(DEBUG_FLAGS)
else
	FLAGS += $(RELEASE_FLAGS)
endif

FLAGS += $(DEFINE_VARS_FLAGS)


#-------------------- targets -------------------------------------------------------

.PHONY: all clean rebuild

all: $(TARGET_ARCHIVE) $(if $(USE_DEBUG), $(foreach dir, $(DEBUG_DIRS_MK), $($(dir))))

$(TARGET_ARCHIVE): $(TREE_OBJ)
	ar rcs $@ $^

$(TREE_OBJ_DIR)/%.o: $(TREE_SRC_DIR)/%.cpp | $(TREE_OBJ_DIR) $(TREE_DEP_DIR)
	$(CXX) $(FLAGS) $(addprefix -I ,$(INCLUDES)) $(DEPFLAGS) -c $< -o $@

-include $(TREE_DEP)

clean:
	rm -rf $(TREE_BUILD_DIR)

rebuild: clean all

$(foreach dir, $(RELEASE_DIRS_MK), $(eval $($(dir)): ; @mkdir -p $$@))
$(foreach dir, $(DEBUG_DIRS_MK),   $(eval $($(dir)): ; @mkdir -p $$@))

#-------------------- end ------------------------------------------------------------