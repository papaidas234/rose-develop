
include_directories(${KDE4_INCLUDES} ${KDE4_INCLUDE_DIR} ${QT_INCLUDES} )


########### install files ###############

install(FILES  stlDOTgraph.h       stlgraph.h DESTINATION ${INCLUDE_INSTALL_DIR})



#original Makefile.am contents follow:

#include $(top_srcdir)/config/Makefile.for.ROSE.includes.and.libs
#
## Header files that need to be included in the distribution
## include_HEADERS = \
##     DOTGraphInterface.h \
##     DOTSubgraphRepresentation.h \
##     DOTSubgraphRepresentation.C \
##     stlDOTgraph.h \
##     stlgraph.h
#
#include_HEADERS = \
#     stlDOTgraph.h \
#     stlgraph.h
#
