cmake_minimum_required (VERSION 3.12)

project(PersonenServiceProjekt)


set(CMAKE_CXX_STANDARD 17)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(OUTPUT_DIR ${CMAKE_SOURCE_DIR}/build/${PLATFORM_ARCHITECTURE}/$<CONFIG>)
set(PROJ_CONFIG $<CONFIG>)


add_executable(
	PersonenServiceProjekt 
	source/main.cpp
		source/persistence/person.h source/persistence/personen_repository.h source/services/personen_service_exception.h source/services/personen_service_impl.h source/services/person_service_impl.cpp)


# Add tests
add_subdirectory(tests)

