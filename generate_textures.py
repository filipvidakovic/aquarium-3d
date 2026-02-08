
"""
Skripta za generisanje placeholder tekstura za akvarijum projekat.
Zahteva: pip install Pillow
"""

try:
    from PIL import Image, ImageDraw, ImageFont
    import os
except ImportError:
    print("ERROR: Potrebna je Pillow biblioteka!")
    print("Instalirajte sa: pip install Pillow")
    exit(1)

def create_wood_texture(size=256):
    img = Image.new('RGB', (size, size))
    draw = ImageDraw.Draw(img)
    
    base_color = (139, 90, 43)
    
    draw.rectangle([0, 0, size, size], fill=base_color)
    
    import random
    random.seed(42)
    for i in range(0, size, 5):
        offset = random.randint(-2, 2)
        darker = tuple(max(0, c - 20) for c in base_color)
        draw.line([(i + offset, 0), (i + offset, size)], fill=darker, width=2)
    
    return img

def create_sand_texture(size=256):
    img = Image.new('RGB', (size, size))
    pixels = img.load()
    
    import random
    random.seed(123)
    
    base_r, base_g, base_b = 194, 178, 128
    
    for y in range(size):
        for x in range(size):
            variation = random.randint(-20, 20)
            r = max(0, min(255, base_r + variation))
            g = max(0, min(255, base_g + variation))
            b = max(0, min(255, base_b + variation))
            pixels[x, y] = (r, g, b)
    
    return img

def create_treasure_texture(size=256):
    img = Image.new('RGB', (size, size))
    draw = ImageDraw.Draw(img)
    
    gold = (255, 215, 0)
    dark_gold = (184, 134, 11)
    
    draw.rectangle([0, 0, size, size], fill=gold)
    
    for i in range(0, size, 20):
        for j in range(0, size, 20):
            if (i + j) % 40 == 0:
                draw.rectangle([i, j, i+10, j+10], fill=dark_gold)
    
    try:
        draw.text((size//4, size//2), "TREASURE", fill=dark_gold)
    except:
        pass
    
    return img

def main():
    if not os.path.exists('res'):
        os.makedirs('res')
        print("Kreiran 'res' folder")
    
    print("Generisanje tekstura...")
    
    wood = create_wood_texture()
    wood.save('res/wood.png')
    print("Kreirana res/wood.png")
    
    sand = create_sand_texture()
    sand.save('res/sand.png')
    print("Kreirana res/sand.png")
    
    treasure = create_treasure_texture()
    treasure.save('res/treasure.png')
    print("Kreirana res/treasure.png")
    
if __name__ == "__main__":
    main()