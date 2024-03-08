PYTHON_INC_PATH=python3 -c 'from sysconfig import get_paths; print(get_paths()["include"])'
PYTHON_INC =$(shell $(PYTHON_INC_PATH))
FLAGS=-fPIC
verlet.so : verlet.c
	gcc --shared -I${PYTHON_INC} $(FLAGS) verlet.c -o verlet.so