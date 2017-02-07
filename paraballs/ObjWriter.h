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

#ifndef OBJWRITER_H
#define OBJWRITER_H

#include <string>
#include <iostream>
#include <fstream>

namespace paraballs
{

void exportOBJ( const std::string filename, TrianglesMesh triangleMesh )
{
    std::ofstream objFile;
    objFile.open( filename );
    objFile << "####\n";
    objFile << "#\n";
    objFile << "# OBJ File generated by Paraballs\n";
    objFile << "#\n";
    objFile << "####\n";
    objFile << "#\n";
    objFile << "# Vertices: " << triangleMesh.vertices.size() << std::endl;
    objFile << "# Faces : " << triangleMesh.indices.size() / 3 << std::endl;
    objFile << "#\n";
    objFile << "####\n";
    for( const auto vertex: triangleMesh.vertices )
        objFile << "v "
                << vertex.x << " " << vertex.y << " " << vertex.z
                << " 1 1 1"
                << "\n";

    for( const auto normal: triangleMesh.normals )
        objFile << "vn "
                << normal.x << " " << normal.y << " " << normal.z
                << "\n";

    for( const auto index: triangleMesh.indices )
    {
        objFile << "f "
                << index.x+1 << "//" << index.x+1 << " "
                << index.y+1 << "//" << index.y+1 << " "
                << index.z+1 << "//" << index.z+1 << "\n";
    }

    objFile << "# End of File\n";
    objFile.close();
    std::cout << "Exported " << triangleMesh.indices.size() / 3
              << " faces" << std::endl;
}

}

#endif // OBJWRITER_H
