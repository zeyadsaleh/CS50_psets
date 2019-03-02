// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: n infile outfile\n");
        return 1;
    }
    int n = atoi(argv[1]);
    if (n <= 0 || n >= 100)
    {
        printf("it must be positive and less than 100\n");
        return 1;
    }
    else
    {

        // remember filenames
        char *infile = argv[2];
        char *outfile = argv[3];

        // open input file
        FILE *inptr = fopen(infile, "r");
        if (inptr == NULL)
        {
            fprintf(stderr, "Could not open %s.\n", infile);
            return 2;
        }

        // open output file
        FILE *outptr = fopen(outfile, "w");
        if (outptr == NULL)
        {
            fclose(inptr);
            fprintf(stderr, "Could not create %s.\n", outfile);
            return 3;
        }

        // read infile's BITMAPFILEHEADER
        BITMAPFILEHEADER bf;
        fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

        // read infile's BITMAPINFOHEADER
        BITMAPINFOHEADER bi;
        fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

        // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
        if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
            bi.biBitCount != 24 || bi.biCompression != 0)
        {
            fclose(outptr);
            fclose(inptr);
            fprintf(stderr, "Unsupported file format.\n");
            return 4;
        }
        int oldbiWidth = bi.biWidth;
        int oldbiHeight = bi.biHeight;
        int oldpadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
        bi.biWidth *= n;
        bi.biHeight *= n;
        int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
        bi.biSizeImage = ((sizeof(RGBTRIPLE) * bi.biWidth) + padding) * abs(bi.biHeight);
        bf.bfSize = bi.biSizeImage + sizeof(BITMAPINFOHEADER) + sizeof(BITMAPFILEHEADER);

        // write outfile's BITMAPFILEHEADER
        fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

        // write outfile's BITMAPINFOHEADER
        fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

        // iterate over infile's scanlines
        for (int i = 0, oldbiHeight2 = abs(oldbiHeight); i < oldbiHeight2; i++)
        {
            for (int v = 0; v < n; v++)
            {
                fseek(inptr, (54 + ((oldbiWidth*3 + oldpadding) * i)), SEEK_SET);
                // iterate over pixels in scanline
                for (int j = 0; j < oldbiWidth; j++)
                {

                    // temporary storage
                    RGBTRIPLE triple;

                    // read RGB triple from infile
                    fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                    for(int h = 0; h < n; h++)
                    {
                        // write RGB triple to outfile
                        fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                    }

                }
            }
             // add padding to outfile
            for (int k = 0; k < padding; k++)
            {
                fputc(0x00, outptr);
            }

            // skip over padding to infile
            fseek(inptr, oldpadding, SEEK_CUR);
        }

        // close infile
        fclose(inptr);

        // close outfile
        fclose(outptr);

        // success
        return 0;
    }
}
