module MultiHolder = {
  let holderImage = MmiAssetsManager.getImage("multi-holder.svg");
  [@react.component]
  let make = () => {
    <img src=holderImage />;
  };
};

module TruckIcon = {
  let truckImage = MmiAssetsManager.getImage("truck.svg");
  [@react.component]
  let make = () => {
    <img src=truckImage />;
  };
};

module BikeIcon = {
  let bikeImage = MmiAssetsManager.getImage("bike.svg");
  [@react.component]
  let make = () => {
    <img src=bikeImage />;
  };
};

module StartTrip = {
  let icon = MmiAssetsManager.getImage("start-trip-icon.svg");
  [@react.component]
  let make = () => {
    <img src=icon />;
  };
};

module AcceptTrip = {
  let icon = MmiAssetsManager.getImage("accept-trip-icon.svg");
  [@react.component]
  let make = () => {
    <img src=icon />;
  };
};

module PickupLocation = {
  let icon = MmiAssetsManager.getImage("pickup-location-icon.svg");
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
  let icon = MmiAssetsManager.getImage("cancel-trip-icon.svg");
  [@react.component]
  let make = () => {
    <img src=icon />;
  };
};

module DropLocation = {
  let icon = MmiAssetsManager.getImage("drop-location-icon.svg");
  [@react.component]
  let make = () => {
    <img src=icon />;
  };
};

module EndTrip = {
  let endTripIcon = MmiAssetsManager.getImage("end-trip-icon.svg");
  [@react.component]
  let make = () => {
    <img src=endTripIcon />;
  };
};

module SingleHolder = {
  let holder = MmiAssetsManager.getImage("single-holder.svg");
  [@react.component]
  let make = () => {
    <img src=holder />;
  };
};

module SliderTruck = {
  let truck = MmiAssetsManager.getImage("slider-truck-thumb.svg");
  [@react.component]
  let make = () => {
    <img src=truck />;
  };
};

module SliderTruckLive = {
  let truck = MmiAssetsManager.getImage("slider-truck-live-thumb.svg");
  [@react.component]
  let make = () => {
    <img src=truck />;
  };
};
