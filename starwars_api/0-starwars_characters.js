#!/usr/bin/node
const request = require('request');

const movieId = process.argv[2];

if (!movieId) {
  console.log('Usage: /0-starwars_characters.js <MOVIE_ID>');
  process.exit(1);
}

const url = `https://swapi.dev/api/films/${movieId}/`;

request(url, function (error, response, body) {
  if (error) {
    console.error('Error:', error);
  } else if (response.statusCode !== 200) {
    console.error('Status code:', response.statusCode);
  } else {
    const film = JSON.parse(body);
    const charactersUrls = film.characters;
    charactersUrls.forEach(characterUrl => {
      request(characterUrl, function (error, response, body) {
        if (error) {
          console.error('Error:', error);
        } else if (response.statusCode !== 200) {
          console.error('Status code:', response.statusCode);
        } else {
          const character = JSON.parse(body);
          console.log(character.name);
        }
      });
    });
  }
});
