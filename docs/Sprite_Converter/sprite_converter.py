import os, sys, glob
from PIL import Image, ImageSequence
images = glob.glob("icons/*")
master_width = 40
master_height = 30
background = Image.new(
        mode='RGBA',
        size=(master_width, master_height),
        color=(0,0,0,0))
background.save('background.png')
background = Image.open("background.png")
for filename in images:
    master = Image.new(
        mode='RGBA',
        size=(master_width, master_height),
        color=(0,0,0,0))
    image = Image.open(filename)
    width, height = image.size
    # master.paste(image)
    master.paste(image,(round((master_width - width)/2),round((master_height - height)/2)))
    # frames = []
    # frame_copy = image.copy()
    # for frame in ImageSequence.Iterator(image):
        # output = background.copy()
        # frame_px = frame.load()
        # output_px = output.load()
        # transparent_foreground = frame.convert('RGBA')
        # transparent_foreground_px = transparent_foreground.load()
        # for x in range(frame.width):
            # for y in range(frame.height):
                # output_px[round((master_width - width)/2) + x, round((master_height - height)/2) + y] = transparent_foreground_px[x, y]
        # frames.append(output)
    # frames.append(frame_copy)
    # if '-front' not in filename and '-old' not in filename:
        # frames[0].save(filename.lower().replace('.gif', '') + '-front.gif', save_all=True, append_images=frames[:-1], duration=50, disposal=2)
    # master.save(filename.replace(filename, filename.replace('pokescape_monsters\\', '').replace('\\icon.png', '.png')).lower().replace('_', ''))
    master.save(filename.replace(filename, filename.replace('icons\\', '')).lower().replace('_', ''))
    # print("\t'" + filename.replace('avatars\\', '').lower().replace('.png', '') + "-prism',")