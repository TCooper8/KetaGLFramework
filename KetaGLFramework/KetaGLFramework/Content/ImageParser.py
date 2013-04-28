import sys, os
import pygame

outfileExtension = ".ki"

def getOutfile(filepath, extension):
    outFilepath = filepath[:filepath.find(".png")] + extension
    return outFilepath

def main(filepath):
    outFilepath = getOutfile(filepath, outfileExtension)

    print >>sys.stdout, "Writing to %s." % outFilepath
    fout = open(outFilepath, "w")

    #surface = pygame.surface( (10, 10) )
    image = pygame.image.load(filepath)
    imageString = pygame.image.tostring(image, "RGBA", False)
    chunksize = 4

    surface = pygame.Surface( (10, 10) )

    print >>fout, "<image>"
    print >>fout, "\t<format> RGBA </format>"
    print >>fout, "\t<width> %s </width>" % image.get_width()
    print >>fout, "\t<height> %s </height>" % image.get_height()

    for x in range(image.get_width()):
        for y in range(image.get_height()):
            (R, G, B, A) = image.get_at( (x, y) )

            print >>fout, "\t<color>", R, G, B, A, "</color>"
    print >>fout, "</image>"

    fout.close()

main(sys.argv[1])
