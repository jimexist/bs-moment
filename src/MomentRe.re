/* duration */
module Duration = {
  type t;
  [@bs.send] external humanize: t => string = "humanize";
  [@bs.send] external milliseconds: t => int = "milliseconds";
  [@bs.send] external asMilliseconds: t => float = "asMilliseconds";
  [@bs.send] external seconds: t => int = "seconds";
  [@bs.send] external asSeconds: t => float = "asSeconds";
  [@bs.send] external minutes: t => int = "minutes";
  [@bs.send] external asMinutes: t => float = "asMinutes";
  [@bs.send] external hours: t => int = "hours";
  [@bs.send] external asHours: t => float = "asHours";
  [@bs.send] external days: t => int = "days";
  [@bs.send] external asDays: t => float = "asDays";
  [@bs.send] external weeks: t => int = "weeks";
  [@bs.send] external asWeeks: t => float = "asWeeks";
  [@bs.send] external months: t => int = "months";
  [@bs.send] external asMonths: t => float = "asMonths";
  [@bs.send] external years: t => int = "years";
  [@bs.send] external asYears: t => float = "asYears";
  [@bs.send] external toJSON: t => string = "toJSON";
  [@bs.send] external toISOString: t => string = "toISOString";
  [@bs.send.pipe: t]
  external asUnitOfTime:
    (
    [@bs.string]
    [
      | `years
      | `quarters
      | `months
      | `weeks
      | `days
      | `hours
      | `minutes
      | `seconds
      | `milliseconds
    ]
    ) =>
    float =
    "as";
};

[@bs.module "moment"]
external duration:
  (
    float,
    [@bs.string] [
      | `years
      | `quarters
      | `months
      | `weeks
      | `days
      | `hours
      | `minutes
      | `seconds
      | `milliseconds
    ]
  ) =>
  Duration.t =
  "duration";

[@bs.module "moment"] external durationMillis: float => Duration.t = "duration";

[@bs.module "moment"]
external durationFormat: string => Duration.t = "duration";

module Moment = {
  type t;
  [@bs.send.pipe: t] external clone: t = "clone";
  [@bs.send] external mutableAdd: (t, Duration.t) => unit = "add";
  let add = (~duration, moment) => {
    let clone = clone(moment);
    mutableAdd(clone, duration);
    clone;
  };
  [@bs.send] external mutableSubtract: (t, Duration.t) => unit = "subtract";
  let subtract = (~duration, moment) => {
    let clone = clone(moment);
    mutableSubtract(clone, duration);
    clone;
  };
  [@bs.send]
  external mutableStartOf:
    (
      t,
      [@bs.string] [
        | `year
        | `quarter
        | `month
        | `week
        | `isoWeek
        | `day
        | `hour
        | `minute
        | `second
        | `millisecond
      ]
    ) =>
    unit =
    "startOf";
  let startOf = (timeUnit, moment) => {
    let clone = clone(moment);
    mutableStartOf(clone, timeUnit);
    clone;
  };
  [@bs.send]
  external mutableEndOf:
    (
      t,
      [@bs.string] [
        | `year
        | `quarter
        | `month
        | `week
        | `isoWeek
        | `day
        | `hour
        | `minute
        | `second
        | `millisecond
      ]
    ) =>
    unit =
    "endOf";
  let endOf = (timeUnit, moment) => {
    let clone = clone(moment);
    mutableEndOf(clone, timeUnit);
    clone;
  };
  [@bs.send] external mutableSetMillisecond: (t, int) => unit = "millisecond";
  let setMillisecond = (millisecond, moment) => {
    let clone = clone(moment);
    mutableSetMillisecond(clone, millisecond);
    clone;
  };
  [@bs.send] external mutableSetSecond: (t, int) => unit = "second";
  let setSecond = (second, moment) => {
    let clone = clone(moment);
    mutableSetSecond(clone, second);
    clone;
  };
  [@bs.send] external mutableSetMinute: (t, int) => unit = "minute";
  let setMinute = (minute, moment) => {
    let clone = clone(moment);
    mutableSetMinute(clone, minute);
    clone;
  };
  [@bs.send] external mutableSetHour: (t, int) => unit = "hour";
  let setHour = (hour, moment) => {
    let clone = clone(moment);
    mutableSetHour(clone, hour);
    clone;
  };
  [@bs.send] external mutableSetDate: (t, int) => unit = "date";
  let setDate = (date, moment) => {
    let clone = clone(moment);
    mutableSetDate(clone, date);
    clone;
  };
  [@bs.send] external mutableSetDay: (t, int) => unit = "day";
  let setDay = (day, moment) => {
    let clone = clone(moment);
    mutableSetDay(clone, day);
    clone;
  };
  [@bs.send] external mutableSetWeekday: (t, int) => unit = "weekday";
  let setWeekday = (weekday, moment) => {
    let clone = clone(moment);
    mutableSetWeekday(clone, weekday);
    clone;
  };
  [@bs.send] external mutableSetIsoWeekday: (t, int) => unit = "isoWeekday";
  let setIsoWeekday = (isoWeekday, moment) => {
    let clone = clone(moment);
    mutableSetIsoWeekday(clone, isoWeekday);
    clone;
  };
  [@bs.send] external mutableSetDayOfYear: (t, int) => unit = "dayOfYear";
  let setDayOfYear = (dayOfYear, moment) => {
    let clone = clone(moment);
    mutableSetDayOfYear(clone, dayOfYear);
    clone;
  };
  [@bs.send] external mutableSetWeek: (t, int) => unit = "week";
  let setWeek = (week, moment) => {
    let clone = clone(moment);
    mutableSetWeek(clone, week);
    clone;
  };
  [@bs.send] external mutableSetIsoWeek: (t, int) => unit = "isoWeek";
  let setIsoWeek = (isoWeek, moment) => {
    let clone = clone(moment);
    mutableSetIsoWeek(clone, isoWeek);
    clone;
  };
  [@bs.send] external mutableSetQuarter: (t, int) => unit = "quarter";
  let setQuarter = (quarter, moment) => {
    let clone = clone(moment);
    mutableSetQuarter(clone, quarter);
    clone;
  };
  [@bs.send] external mutableSetWeekYear: (t, int) => unit = "weekYear";
  let setWeekYear = (weekYear, moment) => {
    let clone = clone(moment);
    mutableSetWeekYear(clone, weekYear);
    clone;
  };
  [@bs.send] external mutableSetIsoWeekYear: (t, int) => unit = "isoWeekYear";
  let setIsoWeekYear = (isoWeekYear, moment) => {
    let clone = clone(moment);
    mutableSetWeekYear(clone, isoWeekYear);
    clone;
  };
  [@bs.send] external mutableSetMonth: (t, int) => unit = "month";
  let setMonth = (month, moment) => {
    let clone = clone(moment);
    mutableSetMonth(clone, month);
    clone;
  };
  [@bs.send] external mutableSetYear: (t, int) => unit = "year";
  let setYear = (year, moment) => {
    let clone = clone(moment);
    mutableSetYear(clone, year);
    clone;
  };
  [@bs.send.pipe: t]
  external get:
    (
    [@bs.string]
    [
      | `year
      | `quarter
      | `month
      | `week
      | `day
      | `date
      | `hour
      | `minute
      | `second
      | `millisecond
    ]
    ) =>
    int =
    "get";
  [@bs.send.pipe: t] external millisecond: int = "millisecond";
  [@bs.send.pipe: t] external second: int = "second";
  [@bs.send.pipe: t] external minute: int = "minute";
  [@bs.send.pipe: t] external hour: int = "hour";
  [@bs.send.pipe: t] external day: int = "day";
  [@bs.send.pipe: t] external date: int = "date";
  [@bs.send.pipe: t] external week: int = "week";
  [@bs.send.pipe: t] external month: int = "month";
  [@bs.send.pipe: t] external year: int = "year";
  [@bs.send.pipe: t] external weekday: int = "weekday";
  [@bs.send] external isValid: t => bool = "isValid";
  [@bs.send] external isBefore: (t, t) => bool = "isBefore";
  [@bs.send] external isAfter: (t, t) => bool = "isAfter";
  [@bs.send]
  external isAfterWithGranularity:
    (
      t,
      t,
      [@bs.string] [
        | `year
        | `month
        | `week
        | `isoWeek
        | `day
        | `hour
        | `minute
        | `second
      ]
    ) =>
    bool =
    "isAfter";
  [@bs.send]
  external isSameOrBeforeWithGranularity:
    (
      t,
      t,
      [@bs.string] [
        | `year
        | `month
        | `week
        | `isoWeek
        | `day
        | `hour
        | `minute
        | `second
      ]
    ) =>
    bool =
    "isSameOrBefore";
  [@bs.send] external isSame: (t, t) => bool = "isSame";
  [@bs.send]
  external isSameWithGranularity:
    (t, t, [@bs.string] [ | `year | `month | `day]) => bool =
    "isSame";
  [@bs.send] external isSameOrBefore: (t, t) => bool = "isSameOrBefore";
  [@bs.send] external isSameOrAfter: (t, t) => bool = "isSameOrAfter";
  [@bs.send] external isBetween: (t, t, t) => bool = "isBetween";
  [@bs.send] external isDST: t => bool = "isDST";
  [@bs.send] external isLeapYear: t => bool = "isLeapYear";
  /* display */
  [@bs.send.pipe: t] external format: string => string = "format";
  [@bs.send.pipe: t] external defaultFormat: string = "format";
  [@bs.send.pipe: t] external utc: string => t = "utc";
  [@bs.send.pipe: t] external defaultUtc: t = "utc";
  [@bs.send.pipe: t] external locale: string => t = "locale";
  [@bs.send]
  external fromNow: (t, ~withoutSuffix: option(bool)) => string = "fromNow";
  [@bs.send]
  external fromMoment: (t, ~other: t, ~format: option(string)) => string =
    "from";
  [@bs.send] external toNow: (t, ~withoutSuffix: option(bool)) => string = "toNow";
  [@bs.send]
  external toMoment: (t, ~other: t, ~format: string) => string = "to";
  [@bs.send] external valueOf: t => float = "valueOf";
  [@bs.send] external daysInMonth: t => int = "daysInMonth";
  [@bs.send] external toJSON: t => Js.null(string) = "toJSON";
  let toJSON = (moment) => toJSON(moment) |> Js.Null.toOption;
  [@bs.send] external toDate: t => Js.Date.t = "toDate";
  [@bs.send] external toUnix: t => int = "unix";
  [@bs.send.pipe: t] external toISOString: (~keepOffset: bool=?) => string = "toISOString";
};

/* parse */

[@bs.module "moment"] external momentNow: unit => Moment.t = "default";

[@bs.module "moment"]
external momentDefaultFormat: string => Moment.t = "default";

[@bs.module "moment"]
external momentWithFormat: (string, string) => Moment.t = "default";

[@bs.module "moment"]
external momentWithDate: Js.Date.t => Moment.t = "default";

[@bs.module "moment"]
external momentWithFormats: (string, array(string)) => Moment.t = "default";

[@bs.module "moment"]
external momentWithTimestampMS: float => Moment.t = "default";

[@bs.module "moment"]
external momentWithComponents: array(int) => Moment.t = "default";

[@bs.module "moment"]
external momentUtcWithFormats: (string, array(string)) => Moment.t = "utc";

[@bs.module "moment"]
external momentUtcDefaultFormat: string => Moment.t = "utc";

let momentWithUnix = (timestamp: int) =>
  momentWithTimestampMS(float_of_int(timestamp) *. 1000.0);

[@bs.send]
external diff:
  (
    Moment.t,
    Moment.t,
    [@bs.string] [
      | `years
      | `quarters
      | `months
      | `weeks
      | `days
      | `hours
      | `minutes
      | `seconds
      | `milliseconds
    ]
  ) =>
  float =
  "diff";

[@bs.send]
external diffWithPrecision:
  (
    Moment.t,
    Moment.t,
    [@bs.string] [
      | `years
      | `quarters
      | `months
      | `weeks
      | `days
      | `hours
      | `minutes
      | `seconds
      | `milliseconds
    ],
    bool
  ) =>
  float =
  "diff";

let momentUtc = (~format=?, value) =>
  switch (format) {
  | Some(f) => momentUtcWithFormats(value, f)
  | None => momentUtcDefaultFormat(value)
  };

let moment = (~format=?, value) =>
  switch (format) {
  | Some(f) => momentWithFormats(value, f)
  | None => momentDefaultFormat(value)
  };
