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

#ifndef PDBREADER_H
#define PDBREADER_H

#include <string>
#include <iostream>
#include <fstream>

namespace
{
const float DEFAULT_RADIUS = 25.f;
const size_t colorMapSize = 113;
}

namespace paraballs
{

/** Structure defining an atom radius in microns
 */
struct AtomicRadius
{
    std::string Symbol;
    float radius;
    int index;
};

/**
 * Structure defining an atom as it is stored in a PDB file
 */
struct Atom
{
    int    processed;
    int    id;
    int    index;
    vec3f  position;
    float  radius;
    int    materialId;
    int    chainId;
    int    residue;
};

static AtomicRadius atomic_radii[colorMapSize] = // atomic radii in microns
{
    { "C"  , 67.f,  1 },
    { "N"  , 56.f,  2 },
    { "O"  , 48.f,  3 },
    { "H"  , 53.f,  4 },
    { "B"  , 87.f,  5 },
    { "F"  , 42.f,  6 },
    { "P"  , 98.f,  7 },
    { "S"  , 88.f,  8 },
    { "V"  ,171.f,  9 },
    { "K"  ,243.f, 10 },
    { "HE" , 31.f, 11 },
    { "LI" ,167.f, 12 },
    { "BE" ,112.f, 13 },
    { "NE" , 38.f, 14 },
    { "NA" ,190.f, 15 },
    { "MG" ,145.f, 16 },
    { "AL" ,118.f, 17 },
    { "SI" ,111.f, 18 },
    { "CL" , 79.f, 19 },
    { "AR" , 71.f, 20 },
    { "CA" ,194.f, 21 },
    { "SC" ,184.f, 22 },
    { "TI" ,176.f, 23 },
    { "CR" ,166.f, 24 },
    { "MN" ,161.f, 25 },
    { "FE" ,156.f, 26 },
    { "CO" ,152.f, 27 },
    { "NI" ,149.f, 28 },
    { "CU" ,145.f, 29 },
    { "ZN" ,142.f, 30 },
    { "GA" ,136.f, 31 },
    { "GE" ,125.f, 32 },
    { "AS" ,114.f, 33 },
    { "SE" ,103.f, 34 },
    { "BR" , 94.f, 35 },
    { "KR" , 88.f, 36 },

    // TODO
    { "OD1" , 25.f, 37 },
    { "OD2" , 25.f, 38 },
    { "CG1" , 25.f, 39 },
    { "CG2" , 25.f, 40 },
    { "CD1" , 25.f, 41 },
    { "CB"  , 25.f, 42 },
    { "CG"  , 25.f, 43 },
    { "CD"  , 25.f, 44 },
    { "OE1" , 25.f, 45 },
    { "NE2" , 25.f, 46 },
    { "CZ"  , 25.f, 47 },
    { "NH1" , 25.f, 48 },
    { "NH2" , 25.f, 49 },
    { "CD2" , 25.f, 50 },
    { "CE1" , 25.f, 51 },
    { "CE2" , 25.f, 52 },
    { "CE"  , 25.f, 53 },
    { "NZ"  , 25.f, 54 },
    { "OH"  , 25.f, 55 },
    { "CE"  , 25.f, 56 },
    { "ND1" , 25.f, 57 },
    { "ND2" , 25.f, 58 },
    { "OXT" , 25.f, 59 },
    { "OG1" , 25.f, 60 },
    { "NE1" , 25.f, 61 },
    { "CE3" , 25.f, 62 },
    { "CZ2" , 25.f, 63 },
    { "CZ3" , 25.f, 64 },
    { "CH2" , 25.f, 65 },
    { "OE2" , 25.f, 66 },
    { "OG"  , 25.f, 67 },
    { "OE2" , 25.f, 68 },
    { "SD"  , 25.f, 69 },
    { "SG"  , 25.f, 70 },
    { "C1*" , 25.f, 71 },
    { "C2" ,  25.f, 72 },
    { "C2*" , 25.f, 73 },
    { "C3*" , 25.f, 74 },
    { "C4" ,  25.f, 75 },
    { "C4*" , 25.f, 76 },
    { "C5" ,  25.f, 77 },
    { "C5*" , 25.f, 78 },
    { "C5M" , 25.f, 79 },
    { "C6" ,  25.f, 80 },
    { "C8" ,  25.f, 81 },
    { "H1" ,  25.f, 82 },
    { "H1*" , 25.f, 83 },
    { "H2" ,  25.f, 84 },
    { "H2*" , 25.f, 85 },
    { "H3" ,  25.f, 86 },
    { "H3*" , 25.f, 87 },
    { "H3P" , 25.f, 88 },
    { "H4" ,  25.f, 89 },
    { "H4*" , 25.f, 90 },
    { "H5" ,  25.f, 91 },
    { "H5*" , 25.f, 92 },
    { "H5M" , 25.f, 93 },
    { "H6" ,  25.f, 94 },
    { "H8" ,  25.f, 95 },
    { "N1" ,  25.f, 96 },
    { "N2" ,  25.f, 97 },
    { "N3" ,  25.f, 98 },
    { "N4" ,  25.f, 99 },
    { "N6" ,  25.f, 100 },
    { "N7" ,  25.f, 101 },
    { "N9" ,  25.f, 102 },
    { "O1P" , 25.f, 103 },
    { "O2" ,  25.f, 104 },
    { "O2P" , 25.f, 105 },
    { "O3*" , 25.f, 106 },
    { "O3P" , 25.f, 107 },
    { "O4" ,  25.f, 108 },
    { "O4*" , 25.f, 109 },
    { "O5*" , 25.f, 110 },
    { "O6" ,  25.f, 111 },
    { "OXT" , 25.f, 112 },
    { "P" ,   25.f, 113 }
};

Spheres importPDBFile( const std::string &filename )
{
    Spheres balls;
    int index(0);
    std::ifstream file(filename.c_str());
    if(!file.is_open())
    {
        std::cerr << "Could not open " << filename << std::endl;
        return balls;
    }
    else
    {
        while( file.good() )
        {
            std::string line;
            std::string value;
            std::getline( file, line );
            if( line.find( "ATOM" ) == 0 || line.find( "HETATM" ) == 0)
            {
                // Atom
                Atom atom;
                atom.chainId = 0;
                atom.residue = 0;
                atom.processed = false;
                atom.index = index;
                index++;
                std::string atomName;
                std::string atomCode;
                size_t i=0;
                while( i<line.length() )
                {
                    switch(i)
                    {
                    case 6: //ID
                    case 12:
                    case 76: // Atom name
                    case 22: // ChainID
                    case 30: // x
                    case 38: // y
                    case 46: // z
                        value = "";
                        break;
                    case 21:
                        atom.chainId = (int)line.at(i)-64;
                        break;
                    case 11:
                        atom.id = static_cast<int>(atoi(value.c_str()));
                        break;
                    case 17:
                        atomCode = value;
                        break;
                    case 79:
                        atomName = value;
                        break;
                    case 26:
                        atom.residue = static_cast<int>(atoi(value.c_str()));
                        break;
                    case 37:
                        atom.position.x = static_cast<float>(atof(value.c_str()));
                        break;
                    case 45:
                        atom.position.y = static_cast<float>(atof(value.c_str()));
                        break;
                    case 53:
                        atom.position.z = static_cast<float>(atof(value.c_str()));
                        break;
                    default:
                        if( line.at(i) != ' ' )
                            value += line.at(i);
                        break;
                    }
                    i++;
                }

                // Material
                atom.materialId = 0;

                // Radius
                atom.radius = DEFAULT_RADIUS;
                i = 0;
                bool found = false;
                while( !found && i<colorMapSize )
                {
                    if( atomName == atomic_radii[ i ].Symbol )
                    {
                        atom.radius = atomic_radii[ i ].radius;
                        found = true;
                    }
                    ++i;
                }

                Sphere s;
                s.material = atom.materialId;
                // convert from nanometers
                s.center.x = 0.01f * atom.position.x;
                s.center.y = 0.01f * atom.position.y;
                s.center.z = 0.01f * atom.position.z;
                // convert from angstrom
                s.radius = 0.0001f * atom.radius;
                balls.push_back( s );
            }
        }
        file.close();
    }

    return balls;
}

}

#endif // PDBREADER_H
