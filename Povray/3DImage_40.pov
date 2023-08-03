#include "colors.inc"
#include "textures.inc"

camera {
    location <30, 20, 10>
    look_at <0, 0, 0>
}

background {
    color rgb <0, 0, 0> // Black color
}

#fopen fp "snapshot_40.txt" read
#while(defined(fp)) 
#read(fp, XYZ) 
sphere {
    XYZ, 0.59
    texture {
        pigment { color rgb <0.83, 0.69, 0.22> } // Gold color
        finish {
            ambient 0.2
            diffuse 0.8
            specular 0
            roughness 0.2 // Controls the matte look
        }
    }
}
#end 
#fclose fp 
light_source { <50, 50, 50> color White }
