# Tesla Routing Project

This project demonstrates a real-time routing tool integrating a C-based backend for fetching routes from the Google Maps Directions API and a React-based frontend for visualizing the route on a map.

## Features
- **Backend (C)**: Uses `libmicrohttpd` for a lightweight HTTP server and `libcurl` to interact with Google Maps API.
- **Frontend (React)**: Displays the map and route, allowing users to visualize the path from origin to destination.
- **Dockerized**: Both backend and frontend can be containerized for easy deployment.
- **Directions & Traffic**: Real-time route calculations powered by the Google Maps API.

## Getting Started
1. Install dependencies (`libmicrohttpd`, `curl`, Node.js).
2. Add your Google Maps API key in `backend/src/route_api.c` and `frontend/.env`.
3. Run `make` in `backend` to build the server.
4. Run `npm start` in `frontend` to start the React development server.

## Docker
Use `docker-compose up --build` at the root of the project to start both containers.

## License
Distributed under the MIT License. See `LICENSE` for more information.
