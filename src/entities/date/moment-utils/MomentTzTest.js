import moment from "moment";
import momentTz from "moment-timezone";

let setTz = (tz) => {
  momentTz.tz.setDefault(tz);
};

let now = () => {
  let date = new Date();
  return momentTz(date).toString();
};

let momentWithTimestampMS = (timestamp) => {
  momentTz(timestamp);
};

let format = (moment, format) => {
  return moment.format(format);
};

let momentWithDate = (date) => {
  return momentTz(date);
};

let toJsDate = (moment) => {
  return moment.toDate();
};

let momentWithFormat = (dateString, format) => {
  return momentTz(dateString, format);
};

let isBefore = (moment_1, moment_2) => {
  return moment_1.isBefore(moment_2);
};

let isAfter = (moment_1, moment_2) => {
  return moment_1.isAfter(moment_2);
};

let getDateTimeAfterElapsedTime = (elapsed_time, time_unit, initial_date) => {
  let toDuration = moment.duration(elapsed_time, time_unit);
  return initial_date.add(toDuration);
};

let getDateTimeBeforeElapsedTime = (elapsed_time, time_unit, initial_date) => {
  let toDuration = moment.duration(elapsed_time, time_unit);
  return initial_date.subtract(toDuration);
};

let startOf = (moment, scale) => {
  return moment.startOf(scale);
};

let endOf = (moment, scale) => {
  return moment.endOf(scale);
};

let valueOf = (moment) => {
  return moment.valueOf();
};

let getTz = () => {
  return momentTz().tz();
};

export {
  setTz,
  now,
  momentWithTimestampMS,
  format,
  momentWithDate,
  toJsDate,
  momentWithFormat,
  isBefore,
  isAfter,
  getDateTimeAfterElapsedTime,
  getDateTimeBeforeElapsedTime,
  startOf,
  endOf,
  valueOf,
  getTz,
};
