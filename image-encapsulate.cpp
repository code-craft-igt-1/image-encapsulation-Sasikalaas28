#include <iostream>
#include <memory>
#include <utility>
#include "./brightener.h"

int main() {
    auto image = std::make_shared<Image>(512, 512);
    std::cout << "Brightening a 512 x 512 image\n";

    // move the ownership of the image to the brightener
    ImageBrightener brightener(image);

    if (image->ValidateImage()) {
        int attenuatedCount = brightener.BrightenWholeImage();
        std::cout << "Attenuated " << attenuatedCount << " pixels\n";

        // Error... cannot access image here! We still need the ownership here!
        std::cout << "... in an image of: " << image->m_rows << " x " << image->m_columns << "\n";
        return 0;
    } else {
        std::cout << "Not a valid image... did nothing\n";
        return 1;
    }
}
