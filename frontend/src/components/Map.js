import React, { useState, useEffect } from "react";

function Map() {
  const [map, setMap] = useState(null);
  const [directionsService, setDirectionsService] = useState(null);
  const [directionsRenderer, setDirectionsRenderer] = useState(null);

  useEffect(() => {
    const script = document.createElement("script");
    script.src = `https://maps.googleapis.com/maps/api/js?key=${process.env.REACT_APP_GOOGLE_MAPS_API_KEY}&libraries=places`;
    script.async = true;
    script.defer = true;
    script.onload = () => {
      const google = window.google;
      const mapObj = new google.maps.Map(document.getElementById("map"), {
        center: { lat: 37.7749, lng: -122.4194 },
        zoom: 7,
      });
      setMap(mapObj);
      setDirectionsService(new google.maps.DirectionsService());
      setDirectionsRenderer(new google.maps.DirectionsRenderer());
    };
    document.head.appendChild(script);
  }, []);

  const fetchDirections = async () => {
    if (!directionsService || !directionsRenderer || !map) return;

    // Fetch route data from backend
    const res = await fetch("http://localhost:8080/route");
    const data = await res.json();

    // Extract start and end from the response (if needed)
    // For this demo, we just hardcoded in backend route_api.c
    // If needed, parse 'data' to get actual start/end.
    const origin = { lat: 37.7749, lng: -122.4194 };
    const destination = { lat: 34.0522, lng: -118.2437 };

    directionsService.route(
      {
        origin: origin,
        destination: destination,
        travelMode: window.google.maps.TravelMode.DRIVING,
      },
      (result, status) => {
        if (status === "OK") {
          directionsRenderer.setDirections(result);
          directionsRenderer.setMap(map);
        } else {
          console.error("Error fetching directions", result);
        }
      }
    );
  };

  return (
    <div>
      <div id="map" style={{ width: "100%", height: "500px", marginBottom: "20px" }}></div>
      <button onClick={fetchDirections}>Get Directions</button>
    </div>
  );
}

export default Map;
