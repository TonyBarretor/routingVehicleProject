# Use Node.js base image
FROM node:16

# Set working directory
WORKDIR /usr/src/app

# Copy package.json and install dependencies
COPY package*.json ./
RUN npm install

# Copy source code
COPY . .

# Build the app
RUN npm run build

# Expose port 3000 and start the app
EXPOSE 3000
CMD ["npm", "start"]
