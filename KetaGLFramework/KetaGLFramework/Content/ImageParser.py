import sys, os
import pygame

fileExtensions = [ ".png" ]
outfileExtension = ".ki"

def parseFile(filepath, fout):
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
    

def getOutfile(filepath, extension):
    outFilepath = filepath[:filepath.find(extension)] + outfileExtension
    return outFilepath

def main(filepath):
    isDir = os.path.isdir(filepath)
    filenameList = []

    if not isDir:
        if not os.path.isfile(filepath):
            print >>sys.stderr, "Error : File path not valid directory or file."
        else:
            filenameList.append(filepath)
    else:
        filenameList = os.listdir(filepath)

    for filename in filenameList:
        extension = filename[filename.rfind('.'):]
        if extension not in fileExtensions:
            continue
        
        fileout = os.path.join(filepath, getOutfile(filename, extension))
        currentFilepath = os.path.join(filepath, filename)

        if os.path.isfile(fileout):
            print "%s already exists, skipping compile." % fileout
            continue
        
        print "Writing to %s." % currentFilepath
        fout = open(fileout, "w")
        parseFile(currentFilepath, fout)
        fout.close()
        
    return

main(sys.argv[1])
