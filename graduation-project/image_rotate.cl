__kernel void imagingTest(
    __read_only  image2d_t srcImg,
    __write_only image2d_t dstImg,
    int width,
    int height,
    double sinAngle,
    double cosAngle)
{
    const sampler_t smp = CLK_NORMALIZED_COORDS_FALSE | CLK_ADDRESS_NONE |CLK_FILTER_LINEAR;
    int2 coord = (int2)(get_global_id(0), get_global_id(1));
    uint4 bgra = read_imageui(srcImg, smp, coord); 
    double x0 = (double)coord.x;
    double y0 = (double)coord.y;
    double x1 = width/2 + ((x0-width/2) * cosAngle + (y0-height/2) * sinAngle) ;
    double y1 = height/2 + ((y0-height/2) * cosAngle - (x0-width/2) * sinAngle) ;

    if( ((int)x1 >= 0 && (int)x1 < width) && ((int)y1 >=0 && (int)y1 < height))
    {
        coord = (int2)((int)x1,(int)y1);
        write_imageui(dstImg, coord, bgra);
    }
}