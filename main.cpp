/* Copyright (c) 2011-2017, EPFL/Blue Brain Project
 *                     Cyrille Favreau <cyrille.favreau@epfl.ch>
 *
 * This file is part of Paraballs
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License version 3.0 as published
 * by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#include "paraballs/MetaballsGenerator.h"
#include "paraballs/PdbReader.h"
#include "paraballs/ObjWriter.h"

using namespace paraballs;

int main( int argc, const char **argv )
{
    if( argc != 4 )
    {
        std::cerr << "usage: paraballs <pdb-file> <grid-size> <threshold>" << std::endl;
        return 1;
    }

    const size_t material = 0;
    const size_t gridSize = atoi(argv[2]);
    const float threshold = atof(argv[3]);

    const std::string pdbFile = argv[1];
    Spheres balls = importPDBFile( pdbFile );

    TrianglesMeshMap trianglesMeshes;
    MetaballsGenerator gen;
    gen.generateMesh( balls, gridSize, threshold, material, trianglesMeshes );
    exportOBJ( "mesh.obj", trianglesMeshes[ material ] );
    return 0;
}
