# creates a qr code given some text

import qrcode
import sys


def usage():
    print("Usage: %s flag_to_put_in_qr_code output_png_filename" % sys.argv[0])
    exit(1)


def main():
    if len(sys.argv) < 3:
        print("Error: 2 arguments required.")
        usage()

    qr_code_data = sys.argv[1]
    output_png_filename = sys.argv[2]

    if not output_png_filename.endswith(".png"):
        print("Error: Output PNG filename must end with '.png'")
        usage()


    img = qrcode.make(qr_code_data)
    img.save(output_png_filename)


if __name__ == "__main__":
    main()
