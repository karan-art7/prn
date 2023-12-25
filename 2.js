// app.js

// Fetch featured content
fetch('https://api.example.com/featured')
  .then(response => response.json())
  .then(data => {
    // Display featured content
    const featuredSection = document.querySelector('.featured');
    data.forEach(item => {
      const featuredItem = document.createElement('div');
      featuredItem.classList.add('featured-item');
      featuredItem.innerHTML = `
        <img src="${item.image}" alt="${item.title}">
        <h3>${item.title}</h3>
      `;
      featuredSection.appendChild(featuredItem);
    });
  })
  .catch(error => console.error(error));

// Fetch movies
fetch('https://api.example.com/movies')
  .then(response => response.json())
  .then(data => {
    // Display movies
    const moviesSection = document.querySelector('.movies');
    data.forEach(movie => {
      const movieItem = document.createElement('div');
      movieItem.classList.add('movie-item');
      movieItem.innerHTML = `
        <img src="${movie.image}" alt="${movie.title}">
        <h4>${movie.title}</h4>
      `;
      moviesSection.appendChild(movieItem);
    });
  })
  .catch(error => console.error(error));

// Fetch TV shows
fetch('https://api.example.com/tv-shows')
  .then(response => response.json())
  .then(data => {
    // Display TV shows
    const tvShowsSection = document.querySelector('.tv-shows');
    data.forEach(tvShow => {
      const tvShowItem = document.createElement('div');
      tvShowItem.classList.add('tv-show-item');
      tvShowItem.innerHTML = `
        <img src="${tvShow.image}" alt="${tvShow.title}">
        <h4>${tvShow.title}</h4>
      `;
      tvShowsSection.appendChild(tvShowItem);
    });
  })
  .catch(error => console.error(error));
