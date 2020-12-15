module MultiHolder = {
  let holderImage = AssetsManager.getImage("multi-holder.svg");
  [@react.component]
  let make = () => {
    <img src=holderImage />;
  };
};

module TruckIcon = {
  let truckImage = AssetsManager.getImage("truck.svg");
  [@react.component]
  let make = () => {
    <img src=truckImage />;
  };
};

module BikeIcon = {
  let bikeImage = AssetsManager.getImage("bike.svg");
  [@react.component]
  let make = () => {
    <img src=bikeImage />;
  };
};

module StartTrip = {
  let icon = AssetsManager.getImage("start-trip-icon.svg");
  [@react.component]
  let make = () => {
    <img src=icon />;
  };
};

module AcceptTrip = {
  let icon = AssetsManager.getImage("accept-trip-icon.svg");
  [@react.component]
  let make = () => {
    <img src=icon />;
  };
};

module PickupLocation = {
  let icon = AssetsManager.getImage("pickup-location-icon.svg");
  [@react.component]
  let make = () => {
    <img src=icon />;
  };
};

module Waypoint = {
  [@react.component]
  let make = (~waypoint: string) => {
    <div className="waypoint-marker"> <div> {React.string(waypoint)} </div> </div>;
  };
};

module CancelTrip = {
  let icon = AssetsManager.getImage("cancel-trip-icon.svg");
  [@react.component]
  let make = () => {
    <img src=icon />;
  };
};

module DropLocation = {
  let icon = AssetsManager.getImage("drop-location-icon.svg");
  [@react.component]
  let make = () => {
    <img src=icon />;
  };
};

module EndTrip = {
  let endTripIcon = AssetsManager.getImage("end-trip-icon.svg");
  [@react.component]
  let make = () => {
    <img src=endTripIcon />;
  };
};

module SingleHolder = {
  let holder = AssetsManager.getImage("single-holder.svg");
  [@react.component]
  let make = () => {
    <img src=holder />;
  };
};

module SliderTruck = {
  let truck = AssetsManager.getImage("slider-truck-thumb.svg");
  [@react.component]
  let make = () => {
    <img src=truck />;
  };
};

module SliderTruckLive = {
  let truck = AssetsManager.getImage("slider-truck-live-thumb.svg");
  [@react.component]
  let make = () => {
    <img src=truck />;
  };
};
