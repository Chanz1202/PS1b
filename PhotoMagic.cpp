/*
NAME: Hanuman Sai Chanukya Srinivas Chilamkuri
Course: COMP 2040
Instructor: Dr Rykalova
PS1b assignment
Due date: 09/27/2021
*/
#include <iostream>
#include <sstream>
#include <string>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "FibLFSR.hpp"

int main(int argc, char* argv[])

{

  if(argc != 4)

  {

    std::cout << "Usage: $ ./PhotoMagic [input file] [output file] [seed] \n";

    return -1;

  }

  // saves the command line arguments to variables

  std::string input_filename(argv[1]);

  std::string output_filename(argv[2]);

  std::string seed(argv[3]);

int tap = 8;

  FibLFSR randomizer(seed, tap);

  // setup the two images

  sf::Image input_image;

  if (!input_image.loadFromFile(input_filename))

  {

    return -1;

  }
  
  sf::Image output_image;

  if (!output_image.loadFromFile(output_filename))

  {

    return -1;

  }

  // p is a pixel

  sf::Color p;

  // for setup two windows

  sf::Vector2u size = input_image.getSize();
  
  // to randomize the bits 

  for(int x= 0; x <(signed)size.x; x++)

  {

    for(int y = 0; y < (signed)size.y; y++)

    {

      p = input_image.getPixel(x, y);

      // XOR the pixels

      p.r = p.r ^ randomizer.generate(tap);

      p.g = p.g ^ randomizer.generate(tap);

      p.b = p.b ^ randomizer.generate(tap);

      output_image.setPixel(x, y, p);

    }

  }
  
  sf::RenderWindow initial_window(sf::VideoMode(size.x, size.y), "Input Image");

  sf::RenderWindow final_window(sf::VideoMode(size.x, size.y), "Output Image");

  // load the images into textures

  sf::Texture input_texture, output_texture;

  input_texture.loadFromImage(input_image);

  output_texture.loadFromImage(output_image);

  // and then load the textures into sprites

  sf::Sprite input_sprite, output_sprite;

  input_sprite.setTexture(input_texture);

  output_sprite.setTexture(output_texture);

  // to open two windows at same time

  while (initial_window.isOpen() && final_window.isOpen())

  {

    sf::Event event;

    while (initial_window.pollEvent(event))

    {

      if (event.type == sf::Event::Closed)

      {

        initial_window.close();

      }

    }

    while (final_window.pollEvent(event))

    {

      if (event.type == sf::Event::Closed)

      {

        final_window.close();

      }

    }


    initial_window.clear();

// input image
    initial_window.draw(input_sprite); 

    initial_window.display();


    final_window.clear();

// output image
    final_window.draw(output_sprite);

    final_window.display();

  }

  // saves the modified output in the latest file

  if (!output_image.saveToFile(output_filename))

  {

    return -1;

  }
  
  return 0;

}
